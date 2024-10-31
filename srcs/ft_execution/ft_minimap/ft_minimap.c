#include <math.h>
#include "cub3d.h"
#include <math.h>

// Определение цветов
#define COLOR_WALL 0x888888
#define COLOR_EMPTY 0xCCCCCC
#define COLOR_PLAYER 0x0000FF
#define COLOR_DIRECTION 0x00FF00
#define COLOR_BORDER 0x000000

#define MINIMAP_SCALE 5
#define MINIMAP_WIDTH 200
#define MINIMAP_HEIGHT 200
#define MINIMAP_OFFSET_X 10
#define MINIMAP_OFFSET_Y 10

// Функция для рисования линии (алгоритм Брезенхэма)
void draw_line(char *data_addr, int size_line, int bytes_per_pixel, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = dx - dy;
	int e2;

	while (1)
	{
		if (x0 >= 0 && x0 < MINIMAP_WIDTH && y0 >= 0 && y0 < MINIMAP_HEIGHT)
		{
			int *dst = (int *)(data_addr + (y0 * size_line) + (x0 * (bytes_per_pixel / 8)));
			*dst = color;
		}
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

// Функция для рисования треугольника направления взгляда
void draw_player_direction(char *data_addr, int size_line, int bytes_per_pixel, int player_x, int player_y, double dir_x, double dir_y, int color)
{
	// Размер стрелки
	int arrow_length = 15;
	int end_x = player_x + (int)(dir_x * arrow_length);
	int end_y = player_y + (int)(dir_y * arrow_length);

	// Нарисуем линию направления взгляда
	draw_line(data_addr, size_line, bytes_per_pixel, player_x, player_y, end_x, end_y, color);

	// Добавим треугольник на конце линии для большей наглядности
	double perp_x = -dir_y;
	double perp_y = dir_x;
	int triangle_size = 5;

	int tri1_x = end_x + (int)(perp_x * triangle_size);
	int tri1_y = end_y + (int)(perp_y * triangle_size);
	int tri2_x = end_x - (int)(perp_x * triangle_size);
	int tri2_y = end_y - (int)(perp_y * triangle_size);

	draw_line(data_addr, size_line, bytes_per_pixel, end_x, end_y, tri1_x, tri1_y, color);
	draw_line(data_addr, size_line, bytes_per_pixel, end_x, end_y, tri2_x, tri2_y, color);
}

// Функция для отрисовки рамки мини-карты
void ft_draw_minimap_border(char *data_addr, int size_line, int bytes_per_pixel, int width, int height, int color)
{
	// Верхняя и нижняя границы
	for (int x = 0; x < width; x++)
	{
		// Верхняя граница
		int *dst_top = (int *)(data_addr + (0 * size_line) + (x * (bytes_per_pixel / 8)));
		*dst_top = color;

		// Нижняя граница
		int *dst_bottom = (int *)(data_addr + ((height - 1) * size_line) + (x * (bytes_per_pixel / 8)));
		*dst_bottom = color;
	}

	// Левая и правая границы
	for (int y = 0; y < height; y++)
	{
		// Левая граница
		int *dst_left = (int *)(data_addr + (y * size_line) + (0 * (bytes_per_pixel / 8)));
		*dst_left = color;

		// Правая граница
		int *dst_right = (int *)(data_addr + (y * size_line) + ((width - 1) * (bytes_per_pixel / 8)));
		*dst_right = color;
	}
}

// Функция для получения цвета стены по типу
int get_wall_color(char wall_type)
{
	if (wall_type == '1')
		return 0xFF0000; // Красный
	else if (wall_type == '2')
		return 0x00FF00; // Зеленый
	else if (wall_type == '3')
		return 0x0000FF; // Синий
	// Добавьте другие типы по необходимости
	else
		return COLOR_WALL; // По умолчанию серый
}

// Основная функция отрисовки мини-карты
void ft_render_minimap(t_map *map)
{
	int x, y;
	void *minimap_img;
	char *data_addr;
	int bytes_per_pixel, size_line, endian;
	int map_width = map->longest_str;
	int map_height = map->real_height;

	// Создаем изображение для мини-карты
	minimap_img = mlx_new_image(map->data->mlx_ptr, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	if (!minimap_img)
	{
		ft_message_error("Error creating minimap image\n");
		return;
	}

	data_addr = mlx_get_data_addr(minimap_img, &bytes_per_pixel, &size_line, &endian);
	if (!data_addr)
	{
		ft_message_error("Error getting minimap data address\n");
		mlx_destroy_image(map->data->mlx_ptr, minimap_img);
		return;
	}

	// Инициализация фона мини-карты
	for (int row = 0; row < MINIMAP_HEIGHT; row++)
	{
		for (int col = 0; col < MINIMAP_WIDTH; col++)
		{
			int *dst = (int *)(data_addr + (row * size_line) + (col * (bytes_per_pixel / 8)));
			*dst = COLOR_EMPTY; // Светло-серый фон
		}
	}

	// Масштабирование
	double scale_x = (double)(MINIMAP_WIDTH - 2) / map_width; // -2 для рамки
	double scale_y = (double)(MINIMAP_HEIGHT - 2) / map_height;
	double scale = scale_x < scale_y ? scale_x : scale_y;

	// Округление масштаба до ближайшего целого числа
	scale = floor(scale);
	if (scale < 1)
		scale = 1;

	// Отрисовка карты
	for (y = 0; y < map_height; y++)
	{
		for (x = 0; x < map_width; x++)
		{
			int pixel_x = (int)(x * scale) + 1; // +1 для рамки
			int pixel_y = (int)(y * scale) + 1;

			int color;

			if (map->grid[y][x] == '1' || map->grid[y][x] == '2' || map->grid[y][x] == '3')
				color = get_wall_color(map->grid[y][x]);
			else
				color = COLOR_EMPTY;

			// Отрисовка квадрата соответствующего цвета
			for (int i = 0; i < scale; i++)
			{
				for (int j = 0; j < scale; j++)
				{
					int current_x = pixel_x + i;
					int current_y = pixel_y + j;

					// Проверка выхода за границы
					if (current_x < MINIMAP_WIDTH - 1 && current_y < MINIMAP_HEIGHT - 1)
					{
						int *dst = (int *)(data_addr + (current_y * size_line) + (current_x * (bytes_per_pixel / 8)));
						*dst = color;
					}
				}
			}
		}
	}

	// Отрисовка игрока с использованием текстуры или круга
	int player_pixel_x = (int)(map->player->x * scale) + 1;
	int player_pixel_y = (int)(map->player->y * scale) + 1;

	int player_size = 5;
	for (int i = -player_size; i <= player_size; i++)
	{
		for (int j = -player_size; j <= player_size; j++)
		{
			if (i * i + j * j <= player_size * player_size)
			{
				int current_x = player_pixel_x + i;
				int current_y = player_pixel_y + j;
				if (current_x >= 1 && current_x < MINIMAP_WIDTH - 1 &&
					 current_y >= 1 && current_y < MINIMAP_HEIGHT - 1)
				{
					int *dst = (int *)(data_addr + (current_y * size_line) + (current_x * (bytes_per_pixel / 8)));
					*dst = COLOR_PLAYER;
				}
			}
		}
	}

	// Отрисовка направления взгляда
	draw_player_direction(data_addr, size_line, bytes_per_pixel, player_pixel_x, player_pixel_y, map->player->dir_x, map->player->dir_y, COLOR_DIRECTION);

	// Отрисовка рамки мини-карты
	ft_draw_minimap_border(data_addr, size_line, bytes_per_pixel, MINIMAP_WIDTH, MINIMAP_HEIGHT, COLOR_BORDER);

	// Отрисовка мини-карты на основном изображении
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, minimap_img, MINIMAP_OFFSET_X, MINIMAP_OFFSET_Y);

	// Освобождение памяти изображения мини-карты
	mlx_destroy_image(map->data->mlx_ptr, minimap_img);
}

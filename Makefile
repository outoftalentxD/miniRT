NAME = miniRT

SRCS =	srcs/minirt.c \
		srcs/parser/get_next_line.c \
		srcs/parser/get_cam.c \
		srcs/parser/utils.c \
		srcs/parser/get_resolution.c \
		srcs/parser/get_ambient.c \
		srcs/parser/get_light.c \
		srcs/parser/get_figure.c \
		srcs/parser/create_new_figure.c \
		srcs/parser/parse_scene.c \
		\
		srcs/tools/lst/init_lst.c \
		srcs/tools/lst/emancipate.c \
		srcs/tools/lst/lst_utils.c \
		srcs/tools/lst/lst_tools.c \
		srcs/tools/lst/create_lst.c \
		srcs/tools/errors/display_err_message.c \
		srcs/tools/errors/struct_errors.c \
		srcs/tools/errors/data_errors.c \
		\
		srcs/core/maths/get_square_root.c \
		srcs/core/maths/vector_operations.c \
		srcs/core/maths/vector_operations_add.c \
		\
		srcs/core/init_mlx.c \
		srcs/core/camera_to_world.c \
		srcs/core/ray_direction.c \
		srcs/core/compute_lights.c \
		srcs/core/color_utils.c \
		srcs/core/render_scene.c \
		srcs/core/compute_intersection.c \
		srcs/core/cylinder_intersection.c \
		srcs/core/square_intersection.c \
		srcs/core/triangle_intersection.c \
		srcs/core/obj_intersection.c \
		\
		srcs/core/utils.c \
		srcs/core/save_option.c \
		srcs/core/tools.c

INCLUDES = srcs/includes 

SETUP_MLX_LINUX = -I/usr/include -Imlx_linux -O3
SETUP_MLX_MACOS = -Imlx

COMP_MLX_LINUX = -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
COMP_MLX_MACOS =  -lmlx -framework OpenGL -framework AppKit
IMAGE = image.bmp

OBJS = ${SRCS:.c=.o}

OBJS_MAIN = ${SRCS_MAIN:.c=.o}

LIB = libft.a

LDIR = srcs/libft

LPATH = srcs/libft/libft.a

MLXPATH = minilibx/libmlx.a
MLXNAME = libmlx.a
MLXDIR = minilibx

DEPENDENCES =	srcs/includes/parser.h \
				srcs/includes/tools.h \
				srcs/includes/struct.h \
				srcs/includes/header.h \
				srcs/includes/graphics.h \
				srcs/includes/operations.h \
				srcs/includes/core.h \
				srcs/libft/libft.h \

CC = gcc

CFLAGS = -Wextra -Wall -Werror 

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}


all: 		${NAME}

$(NAME):	${OBJS} ${DEPENDENCES}
			${MAKE} compilelibft
			${MAKE} compileminilib
			ar rc ${LIB} ${OBJS}
			${CC} ${CFLAGS} ${COMP_MLX_MACOS} ${LIB} ${MLXNAME} -o ${NAME}	

compilelibft:
			${MAKE} -C ${LDIR}
			mv ${LPATH} ${LIB}

compileminilib:
			${MAKE} -C ${MLXDIR}
			mv ${MLXPATH} ${MLXNAME}

clean:
			rm -f ${OBJS}
			rm -f ${LIB}
			rm -f ${MLXNAME}
			rm -f ${IMAGE}
			${MAKE} fclean -C ${LDIR}
			${MAKE} clean -C ${MLXDIR}

fclean: 	clean
			rm -f ${NAME} 

re: 		fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 12:28:37 by sdi-lega          #+#    #+#              #
#    Updated: 2022/10/28 07:50:54 by sdi-lega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#																			   #
#									VARIABLES								   #
#																			   #
################################################################################

NAME				=	cub3D#Name of project.
NAME_B				=	cub3D_bonus#Name of project.

#####################################
#									#
#			Directories				#
#									#
#####################################

#Common#
DIR					=	sources/
OBJ_DIR				=	${DIR}objects/
HDR_DIR				=	${DIR}headers/


#Other#
LIB_DIR				=	libraries/

#####################################
#									#
#			Sources & objects		#
#									#
#####################################

#Common#
C_SRCS				=	main \
						ft_atoi\
						read_line\
						map_parsing\
						parsing\
						file_handling\
						cub3d_utils\
						map_testing\
						init_window\
						raycasting\
						image\
						draw_lines\
						draw_lines_utils\
						raycasting_utils\
						moves\
						moves_utils\
						exit_free\
						horizontal_seeking\
						vertical_seeking

C_SRCS_B			=	main_bonus \
						ft_atoi\
						read_line\
						map_parsing\
						parsing\
						file_handling\
						cub3d_utils\
						map_testing\
						init_window\
						raycasting\
						image\
						draw_lines\
						draw_lines_utils\
						raycasting_utils\
						moves\
						moves_utils_bonus\
						exit_free\
						horizontal_seeking\
						vertical_seeking

SRCS				=	${addsuffix .c, ${C_SRCS}}

SRCS_B				=	${addsuffix .c, ${C_SRCS_B}}

OBJS				=	${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}

OBJS_B				=	${addprefix ${OBJ_DIR}, ${SRCS_B:.c=.o}}

HDRS				= 	${addprefix sources/headers/, ${SRCS:.c=.h}}
DEPENDS				=	${OBJS:.o=.d}
DEPENDS_B			=	${OBJS_B:.o=.d}
EXECUTABLES			=	${NAME} ${NAME_B} #Modify if other executables needed#

#####################################
#									#
#				OTHERS				#
#									#
#####################################

CC					=	cc
INCLUDE				=	-Iincludes -I${DIR}headers/ -Imlx
# INCLUDE				=	-Iincludes -I${DIR}headers/ -Imlx-linux

CC_FLAGS			=	${INCLUDE} -MMD -Wall -Werror -Wextra 
RM					=	rm -f
SLEEP_TIME			=	0.2
SILENT				=	@

################################################################################
#																			   #
#										RULES								   #
#																			   #
################################################################################

#####################################
#									#
#				GENERAL				#
#									#
#####################################

all:				mandatory bonus
re:					fclean all
bonus:				${NAME_B}

mandatory:			${NAME}

#####################################
#									#
#				COMPILING			#
#									#
#####################################
#OBJECTS#
${OBJ_DIR}%.o:		${DIR}%.c
			@ echo  "\rCreating common \"${@F:.c=.o}\" object file.\033[K\c"
			${SILENT} ${CC} ${CC_FLAGS} -I/usr/include -c $< -o $@
			@ sleep ${SLEEP_TIME}

#EXECUTABLES#
${NAME}:				${OBJ_DIR} ${OBJS}
			@ echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} ${OBJS} -o $@ -lmlx -framework OpenGL -framework AppKit
			@ sleep ${SLEEP_TIME}
${NAME_B}:				${OBJ_DIR} ${OBJS_B}
			@ echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} ${OBJS_B} -o $@ -lmlx -framework OpenGL -framework AppKit
			@ sleep ${SLEEP_TIME}
			
# ${NAME}:				${OBJ_DIR} ${OBJS}   #linux
# 			@ echo "\r\"$@\" executable created\033[K"
# 			${SILENT} ${CC} ${OBJS} -o $@ -Lmlx-linux -lmlx_Linux -lXext -lX11 -lm -lz
# 			@ sleep ${SLEEP_TIME}

#-linux -lmlx_Linux -lXext -lX11 -lm -lz
# ./a.out $(find srcs -name "*.c" | sed 's/srcs\///' | awk 'BEGIN {FS="."}{print "srcs/" $1 ".c:includes/"$1".h"}')

headers:
			./Makeheaders $(shell find ${DIR} -name "*.c" | sed 's/${DIR:/=\/}//' | awk 'BEGIN {FS="."}{print "${DIR}"$$1".c:${DIR}headers/"$$1".h"}')


-include ${DEPENDS}
-include ${DEPENDS_B}

debug: CC_FLAGS += -g
debug: fclean mandatory

norm:
		python3 -m c_formatter_42 ${addprefix ${DIR}, ${SRCS}}
		python3 -m c_formatter_42 ${addprefix ${DIR}headers/, ${SRCS:.c=.h}} sources/headers/Philosophers.h

#####################################
#									#
#				CLEANING			#
#									#
#####################################

clean:
			@ echo "\rRemoving objects files.\033[K\c"
			${SILENT} ${RM} ${OBJS} ${DEPENDS}
			@ sleep ${SLEEP_TIME}

clean_bonus:
			@ echo "\rRemoving bonnus objects files.\033[K\c"
			${SILENT} ${RM} ${OBJS_B} ${DEPENDS_B}
			@ sleep ${SLEEP_TIME}

${addprefix clean_,${dir ${ALL_LIBS}}}:
			@ echo "\rRemoving libraries (${patsubst clean_%,%, $@}).\033[K\c"
			${SILENT} make clean -sC ${patsubst clean_%, libraries/%, $@}
			@ sleep ${SLEEP_TIME}

clean_exe:
			@ echo "\rRemoving executables (${notdir ${EXECUTABLES}}).\033[K\c"
			${SILENT} ${RM} ${EXECUTABLES}
			@ sleep ${SLEEP_TIME}

fclean:			clean ${addprefix clean_,${dir ${ALL_LIBS}}} clean_exe clean_bonus
			@ echo "\rEverything removed.\033[K"
				
#####################################
#									#
#			INITIALIZATION			#
#									#
#####################################

${OBJ_DIR}:
			mkdir -p ${OBJ_DIR}
${HDR_DIR}:
			mkdir -p ${HDR_DIR}

start:				${OBJ_DIR} ${HDR_DIR}
			
.phony: 	fclean clean clean_bonus clean_libs clean_exe start all mandatory bonus re 


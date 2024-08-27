# Diretório de destino para os arquivos .o
OBJ_DIR = obj

# Lista de todos os arquivos .cpp no diretório src
CPP_FILES := $(wildcard src/*.cpp)

# Lista de arquivos .o gerados a partir dos arquivos .cpp
OBJ_FILES := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))


# Regra para criar o diretório de objetos
# SEMPRE QUE FOR ADCIONAR MAIS UM INCLUDE LISTAR AQUI
# EXEMPLO:
 $(OBJ_DIR)/%.o: src/%.cpp
	g++ -c -Iinclude \
	-ISFML/include \
	-Iinclude/Entidades \
	-Iinclude/Entidades/Obstaculos \
	-Iinclude/Entidades/Personagens \
	-Iinclude/Entidades/Personagens/Inimigos \
	-Iinclude/Entidades/Personagens/Jogadores \
	-Iinclude/Animcoes \
	-Iinclude/Fases \
	-Iinclude/Fundo \
	-Iinclude/Gerenciadores \
	-Iinclude/IDs \
	-Iinclude/Listas \
	-Iinclude/Estados \
	-Iinclude/Observadores \
	$< -o $@


# Compilação dos arquivos .cpp para arquivos .o 
#$(OBJ_DIR)/%.o: src/%.cpp
#	g++ -c	-Iinclude \
#	-ISFML/include \
#    $< -o $@

# Regra padrão para construir o executável
all: clean compile link

compile: $(OBJ_FILES)

link:
	g++ $(OBJ_FILES) -o main -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio
# Limpar os arquivos .o e o executável
clean:
	rm -rf $(OBJ_DIR)/*.o main
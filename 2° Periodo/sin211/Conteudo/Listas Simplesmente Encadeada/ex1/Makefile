# =============================================================================
# Variáveis de Compilação
# =============================================================================

# Define o compilador C++ a ser usado. g++ é o padrão no Linux.
CXX = g++

# Define as flags de compilação.
# -std=c++17: Usa o padrão C++17 (moderno e recomendado).
# -g          : Inclui informações de debug, essencial para usar o gdb.
# -Wall       : Ativa todos os avisos ("warnings") do compilador. Boa prática!
# -Wextra     : Ativa avisos extras.
CXXFLAGS = -std=c++17 -g -Wall -Wextra

# Define o nome do arquivo executável que será gerado.
TARGET = lse_compilado

# Lista de todos os arquivos fonte (.cpp).
SRCS = main.cpp lse.cpp

# Gera automaticamente a lista de arquivos objeto (.o) a partir dos fontes.
# Ex: main.cpp vira main.o
OBJS = $(SRCS:.cpp=.o)

# =============================================================================
# Regras de Compilação
# =============================================================================

# A primeira regra é a padrão, executada quando você digita apenas "make".
# ".PHONY" diz ao make que "all" não é um arquivo real.
.PHONY: all

# A regra "all" depende da criação do nosso programa (o TARGET).
all: $(TARGET)

# Regra para linkar os arquivos objeto (.o) e criar o executável final.
# Esta regra é acionada quando todos os seus pré-requisitos (.o) estiverem prontos.
$(TARGET): $(OBJS)
	@echo "==> Linkando para criar o executável: $@"
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "==> Executável '$(TARGET)' criado com sucesso!"

# Regra genérica para compilar um arquivo .cpp em um arquivo .o
# A compilação de CADA arquivo .cpp depende do seu .h correspondente.
# Se lse.h mudar, tudo que o inclui deve ser recompilado.
main.o: main.cpp lse.h
	@echo "==> Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

lse.o: lse.cpp lse.h
	@echo "==> Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =============================================================================
# Regras de Limpeza e Execução
# =============================================================================

# ".PHONY" para garantir que "clean" e "run" sempre executem os comandos.
.PHONY: clean run

# Regra para limpar os arquivos gerados pela compilação.
clean:
	@echo "==> Limpando arquivos compilados..."
	rm -f $(OBJS) $(TARGET)
	@echo "==> Limpeza concluída."

# Regra para compilar e executar o programa de uma só vez.
run: all
	@echo "==> Executando o programa..."
	./$(TARGET)
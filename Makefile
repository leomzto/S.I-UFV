CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm  # Biblioteca matemática

# Encontrar todos os arquivos .c, incluindo subdiretórios
SRCS = $(shell find $(CURDIR) -name "*.c" -print)
OBJS = $(patsubst %.c,%.o,$(SRCS))
TARGETS = $(patsubst %.c,%,$(SRCS))

# Regra principal
all: $(TARGETS)

# Compilar os executáveis
$(TARGETS): %: %.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
	rm -f $<  # Remove o arquivo .o após a criação do executável

# Compilar os arquivos .c para .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(OBJS) $(TARGETS)

# Limpeza completa
distclean: clean
	rm -f $(SRCS:.c=.o)

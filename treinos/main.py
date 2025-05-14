import sys
import math
import numpy as np
from PyQt5.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout,
                             QLineEdit, QPushButton, QLabel, QTabWidget, QGridLayout,
                             QComboBox, QGroupBox, QDoubleSpinBox, QColorDialog)
from PyQt5.QtCore import Qt, QSize
from PyQt5.QtGui import QFont, QPalette, QColor


class ScientificCalculator(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Calculadora Científica Avançada")
        self.setMinimumSize(800, 600)
        
        # Configurações padrão
        self.config = {
            'theme': 'dark',
            'font_size': 12,
            'button_size': QSize(60, 40),
            'precision': 10
        }
        
        # Variáveis da calculadora
        self.current_input = ""
        self.last_result = None
        self.memory = 0
        self.radians = True  # Modo radiano/grau
        
        # Inicializa a interface
        self.init_ui()
        self.apply_theme()
        
    def init_ui(self):
        # Widget central e layout principal
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        main_layout = QVBoxLayout(central_widget)
        
        # Cria abas para diferentes funcionalidades
        self.tabs = QTabWidget()
        main_layout.addWidget(self.tabs)
        
        # Aba da calculadora básica/científica
        self.create_calculator_tab()
        
        # Aba de gráficos (seria implementada separadamente)
        self.create_graph_tab()
        
        # Aba de configurações
        self.create_settings_tab()
        
        # Barra de status
        self.status_bar = self.statusBar()
        self.update_status_bar()
    
    def create_calculator_tab(self):
        """Cria a aba principal da calculadora"""
        calculator_tab = QWidget()
        layout = QVBoxLayout(calculator_tab)
        
        # Display
        self.display = QLineEdit()
        self.display.setReadOnly(True)
        self.display.setAlignment(Qt.AlignRight)
        self.display.setStyleSheet("background-color: white; color: black; border: 1px solid gray;")
        self.display.setFont(QFont('Arial', 20))
        layout.addWidget(self.display)
        
        # Mini display para operação atual
        self.mini_display = QLabel()
        self.mini_display.setAlignment(Qt.AlignRight)
        self.mini_display.setFont(QFont('Arial', 10))
        layout.addWidget(self.mini_display)
        
        # Cria os botões
        buttons_layout = QGridLayout()
        
        # Linha 1
        buttons_layout.addWidget(self.create_button("MC", self.memory_clear), 0, 0)
        buttons_layout.addWidget(self.create_button("MR", self.memory_recall), 0, 1)
        buttons_layout.addWidget(self.create_button("M+", self.memory_add), 0, 2)
        buttons_layout.addWidget(self.create_button("M-", self.memory_subtract), 0, 3)
        buttons_layout.addWidget(self.create_button("MS", self.memory_store), 0, 4)
        
        # Linha 2
        buttons_layout.addWidget(self.create_button("sin", lambda: self.function_button("sin(")), 1, 0)
        buttons_layout.addWidget(self.create_button("cos", lambda: self.function_button("cos(")), 1, 1)
        buttons_layout.addWidget(self.create_button("tan", lambda: self.function_button("tan(")), 1, 2)
        buttons_layout.addWidget(self.create_button("π", lambda: self.add_to_input("pi")), 1, 3)
        buttons_layout.addWidget(self.create_button("e", lambda: self.add_to_input("e")), 1, 4)
        
        # Linha 3
        buttons_layout.addWidget(self.create_button("asin", lambda: self.function_button("asin(")), 2, 0)
        buttons_layout.addWidget(self.create_button("acos", lambda: self.function_button("acos(")), 2, 1)
        buttons_layout.addWidget(self.create_button("atan", lambda: self.function_button("atan(")), 2, 2)
        buttons_layout.addWidget(self.create_button("√", lambda: self.function_button("sqrt(")), 2, 3)
        buttons_layout.addWidget(self.create_button("^", lambda: self.add_to_input("^")), 2, 4)
        
        # Linha 4
        buttons_layout.addWidget(self.create_button("log", lambda: self.function_button("log10(")), 3, 0)
        buttons_layout.addWidget(self.create_button("ln", lambda: self.function_button("log(")), 3, 1)
        buttons_layout.addWidget(self.create_button("exp", lambda: self.function_button("exp(")), 3, 2)
        buttons_layout.addWidget(self.create_button("x²", lambda: self.add_to_input("^2")), 3, 3)
        buttons_layout.addWidget(self.create_button("x³", lambda: self.add_to_input("^3")), 3, 4)
        
        # Linha 5
        buttons_layout.addWidget(self.create_button("(", lambda: self.add_to_input("(")), 4, 0)
        buttons_layout.addWidget(self.create_button(")", lambda: self.add_to_input(")")), 4, 1)
        buttons_layout.addWidget(self.create_button("7", lambda: self.add_to_input("7")), 4, 2)
        buttons_layout.addWidget(self.create_button("8", lambda: self.add_to_input("8")), 4, 3)
        buttons_layout.addWidget(self.create_button("9", lambda: self.add_to_input("9")), 4, 4)
        
        # Linha 6
        buttons_layout.addWidget(self.create_button("Rad/Deg", self.toggle_angle_mode), 5, 0)
        buttons_layout.addWidget(self.create_button("!", lambda: self.function_button("factorial(")), 5, 1)
        buttons_layout.addWidget(self.create_button("4", lambda: self.add_to_input("4")), 5, 2)
        buttons_layout.addWidget(self.create_button("5", lambda: self.add_to_input("5")), 5, 3)
        buttons_layout.addWidget(self.create_button("6", lambda: self.add_to_input("6")), 5, 4)
        
        # Linha 7
        buttons_layout.addWidget(self.create_button("+/-", self.toggle_sign), 6, 0)
        buttons_layout.addWidget(self.create_button("%", lambda: self.add_to_input("%")), 6, 1)
        buttons_layout.addWidget(self.create_button("1", lambda: self.add_to_input("1")), 6, 2)
        buttons_layout.addWidget(self.create_button("2", lambda: self.add_to_input("2")), 6, 3)
        buttons_layout.addWidget(self.create_button("3", lambda: self.add_to_input("3")), 6, 4)
        
        # Linha 8
        buttons_layout.addWidget(self.create_button("C", self.clear_input), 7, 0)
        buttons_layout.addWidget(self.create_button("CE", self.clear_all), 7, 1)
        buttons_layout.addWidget(self.create_button("0", lambda: self.add_to_input("0")), 7, 2)
        buttons_layout.addWidget(self.create_button(".", lambda: self.add_to_input(".")), 7, 3)
        buttons_layout.addWidget(self.create_button("=", self.calculate_result), 7, 4)
        
        # Linha 9 - Operações básicas
        buttons_layout.addWidget(self.create_button("+", lambda: self.add_to_input("+")), 8, 0)
        buttons_layout.addWidget(self.create_button("-", lambda: self.add_to_input("-")), 8, 1)
        buttons_layout.addWidget(self.create_button("*", lambda: self.add_to_input("*")), 8, 2)
        buttons_layout.addWidget(self.create_button("/", lambda: self.add_to_input("/")), 8, 3)
        buttons_layout.addWidget(self.create_button("Ans", self.use_last_result), 8, 4)
        
        layout.addLayout(buttons_layout)
        self.tabs.addTab(calculator_tab, "Calculadora")
    
    def create_graph_tab(self):
        """Cria a aba de gráficos (esboço)"""
        graph_tab = QWidget()
        layout = QVBoxLayout(graph_tab)
        
        label = QLabel("Funcionalidade de gráficos será implementada aqui")
        label.setAlignment(Qt.AlignCenter)
        layout.addWidget(label)
        
        self.tabs.addTab(graph_tab, "Gráficos")
    
    def create_settings_tab(self):
        """Cria a aba de configurações"""
        settings_tab = QWidget()
        layout = QVBoxLayout(settings_tab)
        
        # Grupo de configurações de aparência
        appearance_group = QGroupBox("Aparência")
        appearance_layout = QVBoxLayout()
        
        # Tema
        theme_label = QLabel("Tema:")
        self.theme_combo = QComboBox()
        self.theme_combo.addItems(["Claro", "Escuro", "Azul", "Personalizado"])
        self.theme_combo.setCurrentText("Escuro")
        self.theme_combo.currentTextChanged.connect(self.change_theme)
        
        # Cor personalizada
        self.color_button = QPushButton("Escolher Cor")
        self.color_button.clicked.connect(self.choose_custom_color)
        
        # Tamanho da fonte
        font_label = QLabel("Tamanho da fonte:")
        self.font_spin = QDoubleSpinBox()
        self.font_spin.setRange(8, 24)
        self.font_spin.setValue(self.config['font_size'])
        self.font_spin.valueChanged.connect(self.change_font_size)
        
        # Tamanho dos botões
        button_size_label = QLabel("Tamanho dos botões (largura x altura):")
        self.button_width_spin = QDoubleSpinBox()
        self.button_width_spin.setRange(40, 100)
        self.button_width_spin.setValue(self.config['button_size'].width())
        
        self.button_height_spin = QDoubleSpinBox()
        self.button_height_spin.setRange(30, 80)
        self.button_height_spin.setValue(self.config['button_size'].height())
        
        self.button_width_spin.valueChanged.connect(self.update_button_size)
        self.button_height_spin.valueChanged.connect(self.update_button_size)
        
        # Precisão
        precision_label = QLabel("Precisão decimal:")
        self.precision_spin = QDoubleSpinBox()
        self.precision_spin.setRange(0, 15)
        self.precision_spin.setValue(self.config['precision'])
        self.precision_spin.valueChanged.connect(self.change_precision)
        
        # Adiciona widgets ao layout
        appearance_layout.addWidget(theme_label)
        appearance_layout.addWidget(self.theme_combo)
        appearance_layout.addWidget(self.color_button)
        appearance_layout.addWidget(font_label)
        appearance_layout.addWidget(self.font_spin)
        appearance_layout.addWidget(button_size_label)
        appearance_layout.addWidget(self.button_width_spin)
        appearance_layout.addWidget(self.button_height_spin)
        appearance_layout.addWidget(precision_label)
        appearance_layout.addWidget(self.precision_spin)
        
        appearance_group.setLayout(appearance_layout)
        layout.addWidget(appearance_group)
        
        # Botão de reset
        reset_button = QPushButton("Restaurar Padrões")
        reset_button.clicked.connect(self.reset_settings)
        layout.addWidget(reset_button)
        
        layout.addStretch()
        self.tabs.addTab(settings_tab, "Configurações")
    
    def create_button(self, text, handler):
        """Cria um botão com o texto e handler especificados"""
        button = QPushButton(text)
        button.clicked.connect(handler)
        button.setFixedSize(self.config['button_size'])
        button.setFont(QFont('Arial', self.config['font_size']))
        return button
    
    def add_to_input(self, text):
        """Adiciona texto à entrada atual"""
        self.current_input += text
        self.update_display()
    
    def function_button(self, func):
        """Adiciona uma função matemática à entrada"""
        self.current_input += func
        self.update_display()
    
    def clear_input(self):
        """Limpa a entrada atual"""
        self.current_input = ""
        self.update_display()
    
    def clear_all(self):
        """Limpa tudo"""
        self.current_input = ""
        self.last_result = None
        self.update_display()
    
    def toggle_sign(self):
        """Alterna o sinal da entrada atual"""
        if self.current_input.startswith('-'):
            self.current_input = self.current_input[1:]
        else:
            self.current_input = '-' + self.current_input
        self.update_display()
    
    def toggle_angle_mode(self):
        """Alterna entre radianos e graus"""
        self.radians = not self.radians
        self.update_status_bar()
    
    def memory_store(self):
        """Armazena o valor atual na memória"""
        try:
            result = self.evaluate_expression(self.current_input)
            self.memory = result
            self.status_bar.showMessage(f"Valor {result} armazenado na memória", 2000)
        except:
            self.status_bar.showMessage("Erro ao armazenar na memória", 2000)
    
    def memory_recall(self):
        """Recupera o valor da memória"""
        self.current_input += str(self.memory)
        self.update_display()
    
    def memory_add(self):
        """Adiciona o valor atual à memória"""
        try:
            result = self.evaluate_expression(self.current_input)
            self.memory += result
            self.status_bar.showMessage(f"Valor {result} adicionado à memória", 2000)
        except:
            self.status_bar.showMessage("Erro ao adicionar à memória", 2000)
    
    def memory_subtract(self):
        """Subtrai o valor atual da memória"""
        try:
            result = self.evaluate_expression(self.current_input)
            self.memory -= result
            self.status_bar.showMessage(f"Valor {result} subtraído da memória", 2000)
        except:
            self.status_bar.showMessage("Erro ao subtrair da memória", 2000)
    
    def memory_clear(self):
        """Limpa a memória"""
        self.memory = 0
        self.status_bar.showMessage("Memória limpa", 2000)
    
    def use_last_result(self):
        """Usa o último resultado na entrada atual"""
        if self.last_result is not None:
            self.current_input += str(self.last_result)
            self.update_display()
    
    def calculate_result(self):
        """Calcula o resultado da expressão atual"""
        try:
            result = self.evaluate_expression(self.current_input)
            self.last_result = result
            self.current_input = str(result)
            self.update_display()
        except Exception as e:
            self.display.setText("Erro")
            self.status_bar.showMessage(f"Erro no cálculo: {str(e)}", 3000)
    
    def evaluate_expression(self, expr):
        """Avalia a expressão matemática com tratamento de erros"""
        # Substitui constantes e notações
        expr = expr.replace('^', '**').replace('pi', str(math.pi)).replace('e', str(math.e))
        
        # Verifica parênteses balanceados
        if expr.count('(') != expr.count(')'):
            raise ValueError("Parênteses não balanceados")
        
        # Verifica caracteres inválidos
        valid_chars = set('0123456789.+-*/()^%abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_')
        if not all(c in valid_chars for c in expr):
            raise ValueError("Caracteres inválidos na expressão")
        
        # Funções matemáticas
        math_functions = {
            'sin': math.sin if self.radians else lambda x: math.sin(math.radians(x)),
            'cos': math.cos if self.radians else lambda x: math.cos(math.radians(x)),
            'tan': math.tan if self.radians else lambda x: math.tan(math.radians(x)),
            'asin': math.asin if self.radians else lambda x: math.degrees(math.asin(x)),
            'acos': math.acos if self.radians else lambda x: math.degrees(math.acos(x)),
            'atan': math.atan if self.radians else lambda x: math.degrees(math.atan(x)),
            'sqrt': math.sqrt,
            'log10': math.log10,
            'log': math.log,
            'exp': math.exp,
            'factorial': math.factorial
        }
        
        # Avalia a expressão com as funções matemáticas disponíveis
        try:
            result = eval(expr, {'__builtins__': None}, math_functions)
        except Exception as e:
            raise ValueError(f"Erro na avaliação: {str(e)}")
        
        # Arredonda para evitar erros de ponto flutuante
        if isinstance(result, float):
            result = round(result, self.config['precision'])
            if result.is_integer():
                result = int(result)
        
        return result
    
    def update_display(self):
        """Atualiza o display com a entrada atual"""
        self.display.setText(self.current_input)
        self.mini_display.setText(f"Ans = {self.last_result}" if self.last_result is not None else "")
    
    def update_status_bar(self):
        """Atualiza a barra de status"""
        angle_mode = "RAD" if self.radians else "DEG"
        memory_status = f"MEM: {self.memory}" if self.memory != 0 else "MEM: Vazia"
        self.status_bar.showMessage(f"Modo: {angle_mode} | {memory_status} | Precisão: {self.config['precision']} dígitos")
    
    def apply_theme(self, theme=None):
        """Aplica um tema à interface"""
        if theme is None:
            theme = self.config['theme']
        
        palette = QPalette()
        
        if theme == 'dark':
            palette.setColor(QPalette.Window, QColor(53, 53, 53))
            palette.setColor(QPalette.WindowText, Qt.white)
            palette.setColor(QPalette.Base, QColor(25, 25, 25))
            palette.setColor(QPalette.AlternateBase, QColor(53, 53, 53))
            palette.setColor(QPalette.ToolTipBase, Qt.white)
            palette.setColor(QPalette.ToolTipText, Qt.white)
            palette.setColor(QPalette.Text, Qt.white)
            palette.setColor(QPalette.Button, QColor(53, 53, 53))
            palette.setColor(QPalette.ButtonText, Qt.white)
            palette.setColor(QPalette.BrightText, Qt.red)
            palette.setColor(QPalette.Link, QColor(42, 130, 218))
            palette.setColor(QPalette.Highlight, QColor(42, 130, 218))
            palette.setColor(QPalette.HighlightedText, Qt.black)
        elif theme == 'light':
            palette.setColor(QPalette.Window, Qt.white)
            palette.setColor(QPalette.WindowText, Qt.black)
            palette.setColor(QPalette.Base, QColor(240, 240, 240))
            palette.setColor(QPalette.AlternateBase, Qt.white)
            palette.setColor(QPalette.ToolTipBase, Qt.white)
            palette.setColor(QPalette.ToolTipText, Qt.black)
            palette.setColor(QPalette.Text, Qt.black)
            palette.setColor(QPalette.Button, QColor(240, 240, 240))
            palette.setColor(QPalette.ButtonText, Qt.black)
            palette.setColor(QPalette.BrightText, Qt.red)
            palette.setColor(QPalette.Link, QColor(42, 130, 218))
            palette.setColor(QPalette.Highlight, QColor(42, 130, 218))
            palette.setColor(QPalette.HighlightedText, Qt.white)
        elif theme == 'blue':
            palette.setColor(QPalette.Window, QColor(30, 70, 120))
            palette.setColor(QPalette.WindowText, Qt.white)
            palette.setColor(QPalette.Base, QColor(20, 50, 90))
            palette.setColor(QPalette.AlternateBase, QColor(30, 70, 120))
            palette.setColor(QPalette.ToolTipBase, Qt.white)
            palette.setColor(QPalette.ToolTipText, Qt.white)
            palette.setColor(QPalette.Text, Qt.white)
            palette.setColor(QPalette.Button, QColor(30, 70, 120))
            palette.setColor(QPalette.ButtonText, Qt.white)
            palette.setColor(QPalette.BrightText, Qt.red)
            palette.setColor(QPalette.Link, QColor(100, 170, 220))
            palette.setColor(QPalette.Highlight, QColor(100, 170, 220))
            palette.setColor(QPalette.HighlightedText, Qt.black)
        
        self.setPalette(palette)
        self.config['theme'] = theme
    
    def change_theme(self, theme_name):
        """Muda o tema baseado na seleção do usuário"""
        theme_map = {
            "Claro": "light",
            "Escuro": "dark",
            "Azul": "blue",
            "Personalizado": "custom"
        }
        
        theme = theme_map.get(theme_name, "dark")
        
        if theme == "custom":
            self.choose_custom_color()
        else:
            self.apply_theme(theme)
    
    def choose_custom_color(self):
        """Permite ao usuário escolher uma cor personalizada"""
        color = QColorDialog.getColor()
        if color.isValid():
            palette = QPalette()
            palette.setColor(QPalette.Window, color.darker(150))
            palette.setColor(QPalette.WindowText, Qt.white)
            palette.setColor(QPalette.Base, color.darker(200))
            palette.setColor(QPalette.AlternateBase, color.darker(150))
            palette.setColor(QPalette.ToolTipBase, Qt.white)
            palette.setColor(QPalette.ToolTipText, Qt.white)
            palette.setColor(QPalette.Text, Qt.white)
            palette.setColor(QPalette.Button, color.darker(150))
            palette.setColor(QPalette.ButtonText, Qt.white)
            palette.setColor(QPalette.BrightText, Qt.red)
            palette.setColor(QPalette.Link, color.lighter(130))
            palette.setColor(QPalette.Highlight, color.lighter(130))
            palette.setColor(QPalette.HighlightedText, Qt.black)
            
            self.setPalette(palette)
            self.config['theme'] = "custom"
    
    def change_font_size(self, size):
        """Altera o tamanho da fonte"""
        self.config['font_size'] = size
        # Atualiza a fonte de todos os botões
        for tab_index in range(self.tabs.count()):
            tab = self.tabs.widget(tab_index)
            for child in tab.findChildren(QPushButton):
                child.setFont(QFont('Arial', size))
    
    def update_button_size(self):
        """Atualiza o tamanho dos botões"""
        width = self.button_width_spin.value()
        height = self.button_height_spin.value()
        self.config['button_size'] = QSize(width, height)
        
        # Atualiza o tamanho de todos os botões
        for tab_index in range(self.tabs.count()):
            tab = self.tabs.widget(tab_index)
            for child in tab.findChildren(QPushButton):
                child.setFixedSize(QSize(width, height))
    
    def change_precision(self, precision):
        """Altera a precisão decimal"""
        self.config['precision'] = int(precision)
        self.update_status_bar()
    
    def reset_settings(self):
        """Restaura as configurações padrão"""
        self.config = {
            'theme': 'dark',
            'font_size': 12,
            'button_size': QSize(60, 40),
            'precision': 10
        }
        
        # Aplica as configurações
        self.theme_combo.setCurrentText("Escuro")
        self.font_spin.setValue(self.config['font_size'])
        self.button_width_spin.setValue(self.config['button_size'].width())
        self.button_height_spin.setValue(self.config['button_size'].height())
        self.precision_spin.setValue(self.config['precision'])
        
        self.apply_theme()
        self.change_font_size(self.config['font_size'])
        self.update_button_size()
        self.update_status_bar()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    app.setStyle('Fusion')  # Usa o estilo Fusion para melhor aparência
    
    calculator = ScientificCalculator()
    calculator.show()
    
    sys.exit(app.exec_())
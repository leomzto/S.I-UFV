/*
10. Utilize seus conhecimentos para criar um cenário para representar veículo, carro,
moto, caminhão, avião e barco respondendo as seguintes questões:
a. Quais são as características de cada um?
b. Quais são as ações de cada um?
c. De um exemplo de classe e objeto utilizando a linguagem Java.
 */

/*
a) Características
Veículo: marca, modelo, ano, velocidade
Carro: portas, tipoCombustivel
Moto: cilindradas, tipoPartida
Caminhão: cargaMaxima, numeroEixos
Avião: altitudeMaxima, numeroMotores
Barco: tipo, capacidade
b) Ações
Veículo: acelerar(), frear()
Carro: ligarAr()
Moto: empinar()
Caminhão: carregarCarga()
Avião: voar()
Barco: navegar()
 */

// c)
package atv02;


class Veiculo {
    String marca;
    String modelo;
    int ano;
    double velocidade;

    void acelerar() {
        System.out.println("Acelerando...");
    }

    void frear() {
        System.out.println("Freando...");
    }
}

class Carro extends Veiculo {
    int portas;
    String tipoCombustivel;

    void ligarAr() {
        System.out.println("Ar-condicionado ligado");
    }
}

class Moto extends Veiculo {
    int cilindradas;

    void empinar() {
        System.out.println("Empinando a moto");
    }
}

class Caminhao extends Veiculo {
    double cargaMaxima;

    void carregarCarga() {
        System.out.println("Carregando carga");
    }
}

class Aviao extends Veiculo {
    int numeroMotores;

    void voar() {
        System.out.println("Avião está voando");
    }
}

class Barco extends Veiculo {
    int capacidade;

    void navegar() {
        System.out.println("Barco navegando");
    }
}

public class ex10 {
    public static void main(String[] args) {

        Carro carro = new Carro();
        carro.marca = "Toyota";
        carro.modelo = "Corolla";
        carro.ano = 2022;
        carro.portas = 4;

        carro.acelerar();
        carro.ligarAr();

        Aviao aviao = new Aviao();
        aviao.marca = "Boeing";
        aviao.modelo = "737";
        aviao.numeroMotores = 2;

        aviao.voar();
    }
}
package com.ufv.locadora.model;

/**
 * HERANÇA: Caminhonete estende Veiculo — herda todos os atributos e métodos.
 * POLIMORFISMO: implementa calcularCustoLocacao() com regra específica de caminhonete.
 */
public class Caminhonete extends Veiculo {

   private int capacidadeCargaKg;

    public Caminhonete(String placa, String marca, String modelo, int ano,
                 double valorDiaria, int capacidadeCargaKg) {
        super(placa, marca, modelo, ano, valorDiaria);
        this.capacidadeCargaKg = capacidadeCargaKg;
    }

    /*  caminhonetes cobram 25% a mais que o valor base. */
   @Override
    public double calcularCustoLocacao(int numeroDias) { return getValorDiaria() * numeroDias * 1.25; }

    @Override
    public String getTipoVeiculo() {
       return "CAMINHONETE";
   }

    public int getCapacidadeCargaKg() { return capacidadeCargaKg; }

    public void setCapacidadeCargaKg(int capacidadeCargaKg) { this.capacidadeCargaKg = capacidadeCargaKg; }

    @Override
    public String toString() {
        return super.toString() + String.format(" | Capacidade carga: %sKg", capacidadeCargaKg);
    }
}
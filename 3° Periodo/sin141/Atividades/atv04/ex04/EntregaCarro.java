package atv04.ex04;

public class EntregaCarro implements Entrega {

    @Override
    public double calcularFrete(double distancia) {
        double valor = 8 + (2 * distancia);

        if(distancia > 10) valor += 15;

        return valor;
    }

    @Override
    public String getDescricao() {
        return "Entrega por carro";
    }

}
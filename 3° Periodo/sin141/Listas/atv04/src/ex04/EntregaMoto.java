package ex04;

public class EntregaMoto implements Entrega {

    @Override
    public double calcularFrete(double distancia) {
        double valor = 5 + (1.5 * distancia);

        if(distancia > 10) valor += 15;

        return valor;
    }

    @Override
    public String getDescricao() {
        return "Entrega por moto";
    }

}

package ex04;

public class ProcessadorEntrega {
    public void processar(Entrega entrega, double distancia) {
        System.out.println(entrega.getDescricao());
        System.out.println("Frete: R$ " + entrega.calcularFrete(distancia));
    }
}

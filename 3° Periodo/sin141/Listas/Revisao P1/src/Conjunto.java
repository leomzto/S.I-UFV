import java.util.ArrayList;

public class Conjunto {
    private ArrayList<Integer> elementos;


    public Conjunto (){
        elementos = new ArrayList<>();
    }

    public Conjunto (int[] v, int n){
       this();

       for (int i = 0; i < n; i++) {
           insere(v[i]);
       }
    }

    public void insere(int valor) {
    if(!elementos.contains(valor)){
        elementos.add(valor);
        }
    }

    public void retira(int valor){
        elementos.remove(Integer.valueOf(valor));
    }

    public void uniao(Conjunto c1, Conjunto c2) {
        elementos.clear();
        elementos.addAll(c1.elementos);
        for (int elemento : c2.elementos) {
            insere(elemento);
        }
    }

    public void intersecao(Conjunto c1, Conjunto c2){
        elementos.clear();
        for (int elemento : c1.elementos) {
            if (c2.pertence(elemento)) {
                elementos.add(elemento);
            }
        }
    }

    public boolean pertence(int valor){
        return elementos.contains(valor);
    }

    public boolean vazio() {
        return elementos.isEmpty();
    }

    public boolean contem(Conjunto c) {
        return elementos.containsAll(c.elementos);
    }

    public boolean estaContido(Conjunto c){
        return c.elementos.containsAll(this.elementos);
    }

    public boolean igual(Conjunto c){
        return elementos.size() == c.elementos.size() &&
                elementos.containsAll(c.elementos);
    }

    public void imprime(){
        System.out.println(elementos);
    }


}



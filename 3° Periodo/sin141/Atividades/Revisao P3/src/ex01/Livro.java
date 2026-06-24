package ex01;

public class Livro {
    private String isbn;
    private String titulo;
    private String autor;

    public Livro(String isbn, String titulo, String autor){
        if(this.isbn == null || this.isbn.trim().isEmpty()){
            throw new IllegalArgumentException("o ISBN nao pode ser nulo ou vazio");
        }
        if(this.titulo == null || this.titulo.trim().isEmpty()){
            throw new IllegalArgumentException("o Titulo nao pode ser nulo ou vazio");
        }
        if(this.autor == null || this.autor.trim().isEmpty()){
            throw new IllegalArgumentException("o Autor nao pode ser nulo ou vazio");
        }
        this.isbn = isbn.trim();
        this.titulo = titulo.trim();
        this.autor = autor.trim();
    }
    public String getIsbn(){ return this.isbn; }
    public String getTitulo(){ return this.titulo; }
    public String getAutor(){ return this.autor; }
}
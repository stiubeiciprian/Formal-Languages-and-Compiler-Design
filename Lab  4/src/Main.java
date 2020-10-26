public class Main {
    public static void main(String[] args) {
        SymbolTable symbolTable = new SymbolTable();

        System.out.println(symbolTable.pos("cout"));
        System.out.println(symbolTable.pos("cout"));
        System.out.println(symbolTable.pos("print"));
    }
}

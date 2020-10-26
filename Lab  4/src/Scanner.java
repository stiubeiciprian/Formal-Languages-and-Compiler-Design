import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class Scanner {
    private PIF pif;
    private SymbolTable symbolTable;
    private String filename;

    public Scanner(PIF pif, SymbolTable symbolTable, String filename) {
        this.pif = pif;
        this.symbolTable = symbolTable;
        this.filename = filename;
    }

    public void scan() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        String line = reader.readLine();

        while (line != null) {
            String token = detect(line);

            if (isReservedKeyword(token) || isOperator(token) || isSeparator(token)) {
                pif.add(token, 0);
            } else {
                if (isIdentifier(token) || isConstant(token)) {
                    int index = symbolTable.pos(token);
                    pif.add(token, index);
                }
                else {
                    System.out.println("Lexical error.");
                    return;
                }
            }
            line = reader.readLine();
        }
    }

    private String detect(String line) {
        return line;
    }

    private boolean isSeparator(String token) {
        return token.matches("^[\\s,;:()\\[\\]]$");
    }

    private boolean isOperator(String token) {
        return token.matches("^[!=<>]=$|^[+\\-*\\/=<>]$|^and$|^or$|^not$");
    }

    private boolean isReservedKeyword(String token) {
        return token.matches("^int$|^bool$|^char$|^string$|^if$|^else$|^elif$|^input$|^print$|^while$|^for$");
    }

    private boolean isIdentifier(String token) {
        return token.matches("^[a-zA-Z_]+[0-9a-zA-Z_]*$");
    }

    private boolean isConstant(String token) {
        return token.matches("^0|[+-]?[1-9]{1}[0-9]*$") || token.matches("^[\"\\'][a-zA-Z0-9_]*[\\'\"]$");
    }
    
}

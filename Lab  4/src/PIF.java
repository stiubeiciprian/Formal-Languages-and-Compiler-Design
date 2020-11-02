import utils.Pair;

import java.util.ArrayList;

/**
 * Program Internal Form
 *      collection of pairs of (key, value) where:
 *          - the key is a token (identifier/constant);
 *          - the value is 0 in case of constants or the position in symbol table in case of identifiers.
 */
public class PIF {
    private ArrayList<Pair<String, Integer>> pif;

    public PIF() {
        this.pif = new ArrayList<>();
    }

    /**
     * Add token to program internal form.
     * If {@param token} is an identifier, {@param position} should be the position of the identifier in the symbol table.
     * If {@param token} is a constant {@param position} should be 0.
     * @param token
     *        token to be added to the program internal form
     * @param position
     *        position of the token in the symbol table
     *        
     */
    public void add(String token, Integer position) {
        pif.add(new Pair<>(token, position));
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();

        for (Pair<String, Integer> pair: pif) {
            s.append(pair.toString()).append("\n");
        }
        return s.toString();
    }
}

import utils.Pair;

import java.util.ArrayList;

public class PIF {
    ArrayList<Pair<String, Integer>> pif;

    public void add(String token, Integer position) {
        pif.add(new Pair<>(token, position));
    }


}

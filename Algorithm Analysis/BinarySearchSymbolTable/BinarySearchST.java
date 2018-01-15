/**
 * Paige Eckstein
 * Algorithm Analysis
 * 2017
 *
 * BinarySearchST illustrates a symbol table
 * implemented with a binary search tree.
 *
 * Takes input in form of file with letters
 * given one per line
 * Output:
 *
 * size = x
 * min = A
 * max = Y
 *
 * keys()
 * ------
 * A 8
 * B 0
 * C 10
 *
 * etc. for each key and its corresponding last found position
 *
 * select()
 * --------
 * 0 A
 * 1 B
 * 2 C
 *
 * etc. for each key in alphabetical order, numbered for convenience
 *
 * key rank floor ceiling
 * ----------------------
 * A 0 A A
 * B 1 B B
 * C 2 C C
 * D 3 C E
 *
 * etc. for each letter in the alphabet (key)
 * where rank is the number of keys in the symbol table
 * that are strictly less than the key
 * floor is the largest key in the symbol table that is
 * less than or equal to the key
 * and ceiling is the smallest key in the symbol table
 * that is greater tan or equal to the key.
 *
 * To be used with BinarySearchSTTest.java as test client
 * and BSTtest.txt as test input.
 *
 * Example use:
 * java BinarySearchSTTest < BSTtest.txt
 */
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class BinarySearchST<Key extends Comparable<Key>, Value> {

private Key[] keys;
private Value[] vals;
private int N = 0;

// create an empty symbol table with given initial capacity
public BinarySearchST(int capacity) {

        keys = (Key[]) new Comparable[capacity];
        vals = (Value[]) new Object[capacity];

}

// resize the underlying arrays
private void resize(int capacity) {

        assert capacity >= N;
        Key[] tempk = (Key[]) new Comparable[capacity];
        Value[] tempv = (Value[]) new Object[capacity];
        for (int i = 0; i < N; i++) {

                tempk[i] = keys[i];
                tempv[i] = vals[i];

        }
        vals = tempv;
        keys = tempk;

}

// is the key in the table?
public boolean contains(Key key) {

        return get(key) != null;

}

// number of key-value pairs in the table
public int size() {

        return N;

}

// is the symbol table empty?
public boolean isEmpty() {

        return size() == 0;

}

// return the value associated with the given key, or null if no such key
public Value get(Key key) {

        if (isEmpty()) return null;
        int i = rank(key);
        if (i < N && keys[i].compareTo(key) == 0) return vals[i];
        return null;

}

// Returns the number of keys in the symbol table
// that are less than the given key
public int rank(Key key) {

        int lo = 0, hi = N-1;
        while (lo <= hi) {

                int m = lo + (hi - lo) / 2;
                int cmp = key.compareTo(keys[m]);
                if (cmp < 0) hi = m - 1;
                else if (cmp > 0) lo = m + 1;
                else return m;

        }
        return lo;

}

// Search for key. Update value if found; grow table if new.
public void put(Key key, Value val) {

        if (val == null) { delete(key); return; }

        int i = rank(key);

// key is already in table
        if (i < N && keys[i].compareTo(key) == 0) {

                vals[i] = val;
                return;

        }

// insert new key-value pair
        if (N == keys.length) resize(2*keys.length);

        for (int j = N; j > i; j--) {

                keys[j] = keys[j-1];
                vals[j] = vals[j-1];

        }
        keys[i] = key;
        vals[i] = val;
        N++;

}

// Remove the key-value pair if present
public void delete(Key key) {

//If key is null
        if (key == null)
        {
                throw new IllegalArgumentException("Null key.");
        }

//if empty
        if(isEmpty())
        {
                throw new IllegalArgumentException("Empty.");
        }

//get rank
        int rank = rank(key);

//if key doesn't exist in table
        if(rank == N || keys[rank].compareTo(key) != 0)
        {
                throw new IllegalArgumentException("Key doesn't exist in table.");
        }

//shift keys and values
        for(int j = rank; j < N-1; j++)
        {
                keys[j] = keys[j+1];
                vals[j] = vals[j+1];
        }

//Subtract one from N for deleted pair
        N--;

//resize if necessary
        if(N > 0 && N == keys.length/4)
        {
                resize(keys.length/2);
        }

}

// delete the minimum key and its associated value
public void deleteMin() {

        if (isEmpty()) throw new RuntimeException("Symbol table underflow error");
        delete(min());

}

// delete the maximum key and its associated value
public void deleteMax() {

        if (isEmpty()) throw new RuntimeException("Symbol table underflow error");
        delete(max());

}

//Ordered symbol table methods; refer to API for descriptions
public Key min() {

        if (isEmpty()) return null;
        return keys[0];

}

public Key max() {

        if (isEmpty()) return null;
        return keys[N-1];

}

public Key select(int k) {

        if (k < 0 || k >= N) return null;
        return keys[k];

}

//returns largest key in table less than or equal to key
public Key floor(Key key) {

        if(key == null)
        {
                throw new IllegalArgumentException("Null key.");
        }

//get rank
        int rank = rank(key);
        if( rank < N && key.compareTo(keys[rank]) == 0)
        {
                return keys[rank];
        }

        if(rank == 0)
        {
                return null;
        }
        else
        {
                return keys[rank-1];
        }

}

public Key ceiling(Key key) {

        int i = rank(key);
        if (i == N) return null;
        else return keys[i];

}

public int size(Key lo, Key hi) {

        if (lo.compareTo(hi) > 0) return 0;

        if (contains(hi)) return rank(hi) - rank(lo) + 1;

        else return rank(hi) - rank(lo);

}

public Iterable<Key> keys() {

        return keys(min(), max());

}

public Iterable<Key> keys(Key lo, Key hi) {

        Queue<Key> queue = new LinkedList<Key>();
        if (lo == null && hi == null) return queue;
        if (lo == null) throw new RuntimeException("lo is null in keys()");
        if (hi == null) throw new RuntimeException("hi is null in keys()");
        if (lo.compareTo(hi) > 0) return queue;
        for (int i = rank(lo); i < rank(hi); i++)
                queue.offer(keys[i]);
        if (contains(hi)) queue.offer(keys[rank(hi)]);
        return queue;

}

}

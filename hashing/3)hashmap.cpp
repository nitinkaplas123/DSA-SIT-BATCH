Map vs Unordered_map 
1)Map is based on Red Black Tree.
2)Unordered_map is based on hashing.

* It used to store key,value pairs.
* Map stored key value pairs in ordered form as unordered dont.

Time Complexity -:
1) Unordered_Map -> O(1) on average.
2) map           -> O(log(N))


Java -:
1)HashMap 
2)TreeMap 

A HashMap is a collection that stores key-value pairs. It uses a hash table to implement the Map interface, 
allowing for fast retrieval and insertion of elements.
Here's an overview of its key features:
1)Key-Value Pairs: 
  Each element in a HashMap is a key-value pair. The key is used to uniquely identify the associated value.

2)No Duplicate Keys: 
  HashMap does not allow duplicate keys. If you try to insert a key-value pair with a key that already exists
  in the map, the old value associated with that key will be replaced by the new value.

3)Null Keys and Values: 
  HashMap allows one null key and multiple null values.
4)Performance: 
  Retrieving, inserting, and deleting elements from a HashMap is typically very fast, with constant-time 
  performance on average for basic operations (assuming a good hash function and load factor).

5)Ordering: 
  The order of the key-value pairs in a HashMap is not guaranteed. If you need to maintain insertion 
  order or access order, you can use LinkedHashMap.

Here's a simple example demonstrating the use of HashMap:

Code-:

import java.util.HashMap;
public class Main {
    public static void main(String[] args) {
        // Creating a HashMap
        HashMap<String, Integer> map = new HashMap<>();

        // Adding key-value pairs to the HashMap
        map.put("Alice", 25);
        map.put("Bob", 30);
        map.put("Charlie", 35);

        // Accessing values using keys
        System.out.println("Age of Alice: " + map.get("Alice"));
        System.out.println("Age of Bob: " + map.get("Bob"));

        // Updating the value associated with a key
        map.put("Alice", 26); // Update Alice's age
        System.out.println("Updated age of Alice: " + map.get("Alice"));

        // Removing a key-value pair
        map.remove("Charlie");
        System.out.println("HashMap after removing Charlie: " + map);

        // Checking if a key exists
        System.out.println("Is Bob present? " + map.containsKey("Bob"));
    }
}
Output:

Age of Alice: 25
Age of Bob: 30
Updated age of Alice: 26
HashMap after removing Charlie: {Alice=26, Bob=30}
Is Bob present? true
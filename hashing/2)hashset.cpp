C++

Unordered_set -:
All elements are in any order.

Iterators-: 
Iterators are used to point at the memeory address of STL containers.

Functions -:
1)insert() -> to insert the element into hashset.
2)begin() -> return begining position of the containers.
3)end()   -> return the after end position of the containers.
4)size()  -> return the size of hashset.
5)find()  -> to find that particular element is there or not ?
6)erase() -> to erase any element from the hashset.


Applications -:
1)Unordered_set is mainly implemented using hashing.
2)Unordered_set is only works on keys.

Operations-:  Time Complexity on an average is O(1) 
1)search
2)delete
3)insert 


In Java -:
A HashSet is a collection that stores elements using a hash table. It does not allow duplicate elements and 
permits the null element. Here's a brief overview of how it works:

1)Hashing: 
  Internally, HashSet uses a hash function to compute the hash code of each element added to the set.
  This hash code determines the bucket where the element will be stored.
2)No Duplicates: 
  Since HashSet does not allow duplicate elements, if you try to add an element that is 
  already present in the set, the add() method will return false, indicating that the element was not added.
3)Ordering: 
  Unlike some other collections like List or LinkedHashSet, HashSet does not guarantee the order of its elements.
  The order can change over time, especially as elements are added and removed.

Here's a basic example demonstrating the use of HashSet:

Code-:

import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        // Creating a HashSet
        HashSet<String> set = new HashSet<>();

        // Adding elements to the HashSet (insert in C++)
        set.add("Apple");
        set.add("Banana");
        set.add("Orange");
        set.add("Apple"); // Duplicate, won't be added

        // Printing the HashSet
        System.out.println("HashSet: " + set);

        // Checking if an element exists   (find in C++)
        System.out.println("Contains 'Banana': " + set.contains("Banana"));

        // Removing an element   (erase in C++)
        set.remove("Orange");
        System.out.println("HashSet after removing 'Orange': " + set);
    }
}
Output:
HashSet: [Orange, Banana, Apple]
Contains 'Banana': true
HashSet after removing 'Orange': [Banana, Apple]

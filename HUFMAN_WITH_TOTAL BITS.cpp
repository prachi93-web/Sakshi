#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) {
        left = right = nullptr;
        this->ch = ch;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* lr, Node* ri) {
        return lr->freq > ri->freq;
    }
};

// Function to print Huffman codes and calculate the total size
void print(Node* root, string str, unordered_map<char, string> &huffmanCodes)//By passing it by reference, any changes made to huffmanCodes inside the function will directly modify the original map in the calling code.
 {
    if (!root)
        return;

    // If it's a leaf node, print the character and its code
    if (root->ch != '$') {//means  equls to leaf node
        cout << root->ch << ": " << str << "\n";//charater stored in the current node
        huffmanCodes[root->ch] = str; // Store the code in the map
    }

    print(root->left, str + "0", huffmanCodes);
    print(root->right, str + "1", huffmanCodes);
}

void make_tree(string text) {
    unordered_map<char, int> freq;//e unordered_map<char, int> freq; is used to store the frequency of each character in the string text
    for (char ch : text)//for (char ch : text) iterates over every character ch in the string text.
        freq[ch]++;

    priority_queue<Node*, vector<Node*>, compare> pq;//playing role of minheap and will extract the nodes w/t lowest frquenct=y

    for (auto pair : freq)//iterates through each character-frequency pair in the freq map.
        pq.push(new Node(pair.first, pair.second));//usedfor creating new node character and pq is the priority queue function which is used extract nodes with lowest frequency

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();//The node with the smallest frequency is extracted from the priority queue and assigned to left.
        Node *right = pq.top(); pq.pop();//second smallest freaquency is extracted
        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);//The newly created internal node top is pushed back into the priority queue.
    }//so this loop will continue and nodes continue combining untill only one node remains that will becam a root of huffman tree

    // Map to store Huffman codes
    unordered_map<char, string> huffmanCodes;
    
    // Print Huffman codes and store them in the map
    cout << "\nHuffman Codes:\n"; 
    print(pq.top(), "", huffmanCodes);//calls the print function to traverse the huffman tree

    // Calculate the total size of the encoded message
    int totalSize = 0;
    for (char ch : text) {
        totalSize += huffmanCodes[ch].length();
    }

    cout << "\nTotal Size of Encoded Message: " << totalSize << " bits" << endl;
}

int main() {
    string text;
    cout << "Enter string: ";
    cin >> text;
    make_tree(text);
    return 0;
}
/*explanation:https://chatgpt.com/share/...
https://chatgpt.com/share/67251a16-8650-800c-a7ad-1b80eec5ee18
print(root->left, str + "0", huffmanCodes);
print(root->right, str + "1", huffmanCodes);
These two lines are responsible for the recursive traversal of the Huffman Tree.

Left Child:

If we move to the left child of a node, we append '0' to the current Huffman code (str).
This means all characters in the left subtree will have codes starting with '0'.
Right Child:

If we move to the right child of a node, we append '1' to the current Huffman code (str).
This means all characters in the right subtree will have codes starting with '1'.
The recursion continues until it reaches the leaf nodes, where the complete Huffman code for each character is printed and stored.

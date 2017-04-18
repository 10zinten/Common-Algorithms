#include<bits/stdc++.h>
using namespace std;

//A tree Node
struct Node {
    char ch;
    int freq;
    Node *left;
    Node *right;
};

// Function to create and return Nee Node
Node *getNode(char ch, int freq, Node* left, Node* right) {
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
};

struct comp {
    bool operator()(Node* l, Node* r) {
        // highest priory item has loweset frequency
        return l->freq > r->freq;
    }
};

void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {

    //Base case, reached leaf Node
    if(root == nullptr)
        return;

    if(!root->left && !root->right)
        huffmanCode[root->ch] = str;

    //Preorder traversal
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);

}

void buildHuffmanTree(string text) {

    //Map stores the frequency each character in the string
    unordered_map<char, int> freq;
    for (char ch: text)
        freq[ch]++;

    // Priority Queue to store Node of the huffman Tree
    priority_queue<Node*, vector<Node*>, comp> pq;

    //Create Node for each chracter
    //Add to the priority Queue
    for(auto it: freq)
        pq.push(getNode(it.first, it.second, nullptr, nullptr));

    //Building Huffman Tree
    while(pq.size() != 1) {

        //remove two nodes of highest priority
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Create a Parent node and these two nodes as children
        // parent frequency is sum of the its two children frequency
        int sum = left->freq + right->freq;
        pq.push(getNode('\0',sum, left, right));
    }

    // Take root of the huffman Tree
    Node* root = pq.top();

    //Do preoder Traversal on Huffman Tree
    //Store the Huffman Code in Map.
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout<<"Huffman Codes are: "<<endl;
    for(auto it: huffmanCode)
        cout<<it.first<<" : "<<it.second<<endl;

}

int main() {
    string text= "hello world";

    cout<<"Original Test: "<<text<<endl<<endl;

    buildHuffmanTree(text);

    return 0;
}

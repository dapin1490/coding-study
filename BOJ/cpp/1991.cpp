#include <iostream>
#include <map>
#include <stack>
using namespace std;

void boj1991();
void preorder(char root, map<char, pair<char, char>>& tree);
void inorder(char root, map<char, pair<char, char>>& tree);
void postorder(char root, map<char, pair<char, char>>& tree);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj1991();

    return 0;
}

void boj1991() {
    int n;
    char root, left, right;
    char first_root;
    map<char, pair<char, char>> tree;

    cin >> n;

    cin >> first_root >> left >> right;
    tree[first_root] = make_pair(left, right);
    for (int i = 1; i < n; i++) {
        cin >> root >> left >> right;
        tree[root] = make_pair(left, right);
    }

    preorder(first_root, tree);
    inorder(first_root, tree);
    cout << "\n";
    postorder(first_root, tree);
    cout << "\n";

    return;
}

void preorder(char root, map<char, pair<char, char>>& tree) {
    stack<char> next_node;
    char node;

    next_node.push(root);
    while (!next_node.empty()) {
        node = next_node.top();
        next_node.pop();
        if (node != '.') {
            cout << node;
            next_node.push(tree[node].second);
            next_node.push(tree[node].first);
        }
    }
    cout << "\n";

    return;
}

void inorder(char root, map<char, pair<char, char>>& tree) {
    if (root == '.')
        return;
    if (tree[root].first != '.' || tree[root].second != '.') {
        inorder(tree[root].first, tree);
        cout << root;
        inorder(tree[root].second, tree);
    }
    else
        cout << root;

    return;
}

void postorder(char root, map<char, pair<char, char>>& tree) {
    if (root == '.')
        return;
    if (tree[root].first != '.' || tree[root].second != '.') {
        postorder(tree[root].first, tree);
        postorder(tree[root].second, tree);
        cout << root;
    }
    else
        cout << root;

    return;
}
#include <iostream>
#include <queue>
using namespace std;

/// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

// Inisialisasi
void init() {
    root = NULL;
}

// Cek Node
int isEmpty() {
    return root == NULL;
}

// Buat Node Baru
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon* insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Tambah Kanan
Pohon* insertRight(char data, Pohon *node) {
    if (root == NULL) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Ubah Data Tree
void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

// Cari Data Tree
void find(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            if (node != root) {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            return max(heightKiri, heightKanan) + 1;
        }
    }
}

// Karakteristik Tree
void characteristic() {
    cout << "\nSize Tree : " << size(root) << endl;
    cout << "Height Tree : " << height(root) << endl;
    cout << "Average Node of Tree : " << (float)size(root) / height(root) << endl;
}

// Display Child and Descendants
void displayChildAndDescendants(Pohon *node) {
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }

    cout << "\nData Node : " << node->data << endl;

    if (node->left) {
        cout << "Child Kiri : " << node->left->data << endl;
    } else {
        cout << "Child Kiri : (tidak punya Child kiri)" << endl;
    }

    if (node->right) {
        cout << "Child Kanan : " << node->right->data << endl;
    } else {
        cout << "Child Kanan : (tidak punya Child kanan)" << endl;
    }

    cout << "Descendants : ";
    queue<Pohon*> q;
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
    while (!q.empty()) {
        Pohon* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

// Menu
void menu() {
    int pilihan;
    char data;
    Pohon *node = nullptr;

    do {
        cout << "\nMenu:\n";
        cout << "1. Buat Node\n";
        cout << "2. Tambah Kiri\n";
        cout << "3. Tambah Kanan\n";
        cout << "4. Ubah Data\n";
        cout << "5. Lihat Isi Data\n";
        cout << "6. Cari Data\n";
        cout << "7. PreOrder\n";
        cout << "8. InOrder\n";
        cout << "9. PostOrder\n";
        cout << "10. Hapus SubTree\n";
        cout << "11. Hapus Tree\n";
        cout << "12. Karakteristik Tree\n";
        cout << "13. Tampilkan Child dan Descendants\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data node root: ";
                cin >> data;
                buatNode(data);
                break;
           case 2:
    if (!isEmpty()) {
        cout << "Masukkan data node: ";
        cin >> data;
        char parentData;
        cout << "Masukkan data node parent: ";
        cin >> parentData;

        // Mencari node parent
        Pohon* parentNode = nullptr;
        queue<Pohon*> q;
        q.push(root);
        while (!q.empty()) {
            Pohon* current = q.front();
            q.pop();
            if (current->data == parentData) {
                parentNode = current;
                break;
            }
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        // Menambahkan node kiri jika ditemukan parent
        if (parentNode) {
            insertLeft(data, parentNode);
        } else {
            cout << "Node parent tidak ditemukan!" << endl;
        }
    }
    else {
        cout << "Tree belum dibuat. Pilih menu 1 untuk membuat tree terlebih dahulu.\n";
    }
    break;
            case 3:
                if (!isEmpty()) {
                    cout << "Masukkan data node: ";
                    cin >> data;
                    cout << "Masukkan data node parent: ";
                    cin >> node->data;
                    node = root;
                    if (node->data == root->data) {
                        insertRight(data, node);
                    }
                    else {
                        queue<Pohon*> q;
                        q.push(root);
                        while (!q.empty()) {
                            Pohon* current = q.front();
                            q.pop();
                            if (current->data == node->data) {
                                insertRight(data, current);
                                break;
                            }
                            if (current->left) q.push(current->left);
                            if (current->right) q.push(current->right);
                        }
                    }
                }
                else {
                    cout << "Tree belum dibuat. Pilih menu 1 untuk membuat tree terlebih dahulu.\n";
                }
                break;
            case 4:
                if (!isEmpty()) {
                    cout << "Masukkan data baru: ";
                    cin >> data;
                    cout << "Masukkan data node yang ingin diubah: ";
                    cin >> node->data;
                    node = root;
                    if (node->data == root->data) {
                        update(data, node);
                    }
                    else {
                        queue<Pohon*> q;
                        q.push(root);
                        while (!q.empty()) {
                            Pohon* current = q.front();
                            q.pop();
                            if (current->data == node->data) {
                                update(data, current);
                                break;
                            }
                            if (current->left) q.push(current->left);
                            if (current->right) q.push(current->right);
                        }
                    }
                }
                else {
                    cout << "Tree belum dibuat. Pilih menu 1 untuk membuat tree terlebih dahulu.\n";
                }
                break;
            case 5:
                if (!isEmpty()) {
                    cout << "Masukkan data node yang ingin dilihat: ";
                    cin >> node->data;
                    node = root;
                    if (node->data == root->data) {
                        retrieve(node);
                    }
                    else {
                        queue<Pohon*> q;
                        q.push(root);
                        while (!q.empty()) {
                            Pohon* current = q.front();
                            q.pop();
                            if (current->data == node->data) {
                                retrieve(current);
                                break;
                            }
                            if (current->left) q.push(current->left);
                            if (current->right) q.push(current->right);
                        }
                    }
                }
                else {
                    cout << "Tree belum dibuat. Pilih menu 1 untuk membuat tree terlebih dahulu.\n";
                }
                break;
            case 6:
                if (!isEmpty()) {
                    cout << "Masukkan data node yang ingin dicari: ";
                    cin >> node->data;
                    node = root;
                    if (node->data == root->data) {
                        find(node);
                    }
                    else {
                        queue<Pohon*> q;
                        q.push(root);
                        while (!q.empty()) {
                            Pohon* current = q.front();
                            q.pop();
                            if (current->data == node->data) {
                                find(current);
                                break;
                            }
                            if (current->left) q.push(current->left);
                            if (current->right) q.push(current->right);
                        }
                    }
                }
                else {
                    cout << "Tree belum dibuat. Pilih menu 1 untuk membuat tree terlebih dahulu.\n";
                }
                break;
            case 7:
                cout << "\nPreOrder :" << endl;
                preOrder(root);
                cout << "\n" << endl;
                break;
            case 8:
                cout << "\nInOrder :" << endl;
                inOrder(root);
                cout << "\n" << endl;
                break;
            case 9:
                cout << "\nPostOrder :" << endl;
                postOrder(root);
                cout << "\n" << endl;
                break;
            case 10:
                if (!isEmpty()) {
                    cout << "Masukkan data node subtree yang ingin dihapus: ";
                    cin >> node->data;
                    node = root;
                    if (node->data == root->data) {
                        deleteSub(node);
                    }
                    else {
                        queue<Pohon*> q;
                        q.push(root);
                        while (!q.empty()) {
                            Pohon* current = q.front();
                            q.pop();
                            if (current->data == node->data) {
                                deleteSub(current);
                                break;
                            }
                            if (current->left) q.push(current->left);
                            if (current->right) q.push(current->right);
                        }
                    }
                }
                else {
                    cout << "Tree belum dibuat. Pilih menu 1 untuk membuat tree terlebih dahulu.\n";
                }
                break;
            case 11:
                clear();
                break;
            case 12:
                characteristic();
                break;
            case 13:
    if (!isEmpty()) {
        cout << "Masukkan data node yang ingin dilihat child dan descendants-nya: ";
        cin >> data;
        // Mencari node yang sesuai
        Pohon* targetNode = nullptr;
        queue<Pohon*> q;
        q.push(root);
        while (!q.empty()) {
            Pohon* current = q.front();
            q.pop();
            if (current->data == data) {
                targetNode = current;
                break;
            }
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        // Jika node ditemukan, tampilkan child dan descendants-nya
        if (targetNode) {
            displayChildAndDescendants(targetNode);
        } else {
            cout << "Node tidak ditemukan!" << endl;
        }
    }
    else {
        cout << "Tree belum dibuat. Pilih menu 1 untuk membuat tree terlebih dahulu.\n";
    }
    break;

            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilihan != 0);
}

int main() {
    menu();
    return 0;
}

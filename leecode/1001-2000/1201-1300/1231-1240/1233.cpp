#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    struct FileTree
    {
        string name;
        bool end;
        vector<FileTree*> children;
    };
    FileTree* AddChildOneLevel(FileTree* tree, string child)
    {
        if (nullptr == tree) {
            return tree;
        }
        if (tree->end) {
            return nullptr;
        }
        for (int i = 0; i < tree->children.size(); i++) {
            if (tree->children[i]->name == child) {
                return tree->children[i];
            }
        }
        FileTree* new_tree = new FileTree;
        new_tree->name = child;
        new_tree->end = false;
        tree->children.push_back(new_tree);
        return new_tree;
    }
    void AddChild(FileTree* tree, string child)
    {
        FileTree* copy = tree;
        string child_level = "/";
        for (int i = 1; i < child.size(); i++) {
            child_level += child[i];
            if (i + 1 == child.size() || child[i + 1] == '/') {
                copy = AddChildOneLevel(copy, child_level);
                child_level = "";
                if (copy == nullptr) {
                    break;
                }
            }
        }
        if (nullptr != copy && !copy->end) {
            copy->children.clear();
            copy->end = true;
        }
    }
    void GetDirs(FileTree* tree, string parent, vector<string>& res)
    {
        for (int i = 0; i < tree->children.size(); i++) {
            GetDirs(tree->children[i], parent + tree->name, res);

        }
        if (tree->end) {
            res.push_back(parent + tree->name);
        }
    }
    vector<string> removeSubfolders(vector<string>& folder)
    {
        FileTree* tree = new FileTree;
        tree->name = "";
        tree->end = false;
        for (int i = 0; i < folder.size(); i++) {
            AddChild(tree, folder[i]);
        }
        vector<string> res;
        GetDirs(tree, "", res);
        return res;
    }
};

int main()
{
    vector<string> src = {"/a","/a/b/c","/a/b/d"};
    Solution s;
    vector<string> res = s.removeSubfolders(src);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\t";
    }
}
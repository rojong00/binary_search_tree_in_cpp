● OBJECTIVE
<br>
1. BST tree in cpp
   - Done until making a tree representing a binary tree, but it's not working well So i need to revise that
![](https://github.com/rojong00/binary_search_tree_in_cpp/blob/main/img/execution.png)
      
3. git techique
   - SITUATION : amend bst.cpp in local and remote repo simultaneously
   - When executing,
```
     git pull --rebase origin main
```
   OR
   
```bash
     git pull origin main --no-rebase
```

   An ERR occurred indicating that there is a same named function in bst.cpp
   - so manual amending was required.
<br>
● below is a sequential commit
```bash
          git log --oneline --graph --all
```
- rebase
![](https://github.com/rojong00/binary_search_tree_in_cpp/blob/main/img/rebase.png)
- merge (no-rebase)
![](https://github.com/rojong00/binary_search_tree_in_cpp/blob/main/img/merge.png)

// generic skil list class

const int maxLevel = 4;

template<class T>
class SkipListNode {
    public:
    SkipListNode() {}
    T key;
    SkipListNode **next;
};

template<class T>
class SkipList {
    public:
    SkipList();
    void choosePowers();
    int chooseLevel();
    T* skipListSearch(const T&);
    void skipListInsert(const T&);
    private:
    typedef SkipListNode<T> *nodePtr;
    nodePtr root[maxLevel];
    int powers[maxLevel];
};


template<class T>
SkipList<T>::SkipList() {
    for(int i = 0; i < maxLevel; i++)
        root[i] = 0;
}

template<class T>
void SkipList<T>::choosePowers() {
    powers[maxLevel - 1] = (2 << (maxLevel-1)) - 1; // 2 ^maxlevel -1
    for(int i = maxLevel -2 ;j = 0; i>= 0; i--, j++)
        powers[i] = powers[i+1] - (2 << j);
}
template<class T>
int SkipList<T>::chooseLevel() {
    int i, r = rand() % powers[maxLevel - 1] + 1;
    for (i = 1;  i < maxLevel; i++) 
        if(r < powers[i])
            return i-1; // return a level < the highes level
        return i-1; // reutrn the highest level
}
template<class T>
T* SkipList<T>::skipListSearch(const T& key) {
    nodePtr prev, curr;
    int lvl;
    for (lvl = maxLevel-1; lvl >= 0 && !root[lvl]; lvl--);
    prev = curr = root[lvl];
    while(1) {
        if(key == curr->key)    // succes if equal
            return &curr->key;
        else if(key < curr->key){ // if smalller, go down
            if(lvl == 0) //if possible
                return 0;
            else if(curr = root[lvl]) // by one level
                curr = root[--lvl]; // starting form the 
            else curr = *(prev->next + --lvl);//predecessor which
        }//can be the root
        else { // if greater
            prev = curr; // go to the next
            if(*(curr->next + lvl) != 0) //non-null next
             curr = *(curr->next + lvl);//on the same level
            else {// or to a list on an
                //lowe level
                for(lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl--);
                if(lvl >= 0)
                    curr = *(curr->next + lvl);
                else return 0;
            }
        }
    }
}

template<class T>
void SkipList<T>::skipListInsert(const T& key) {
    nodePtr curr[maxLevel], prev[maxLevel], newNode;
    int lvl, i;
    curr[maxLevel-1] = root[maxLevel-1];
    prev[maxLevel-1] =0;
    for(lvl = maxLevel -1; lvl >= 0; lvl--){
        while(curr[lvl] && curr[lvl]->key < key) {
            prev[lvl] = curr[lvl];
            curr[lvl] = *(curr[lvl]->next + lvl);
        }
        if(curr[lvl] && curr[lvl]->key ==key )
            return;
        if(lvl > 0)
            if(prev[lvl] == 0) {
                curr[lvl-1] = root[lvl-1];
                prev[lvl-1] = 0;
            } 
            else {
                curr[lvl-1] = *(prev[lvl]->next + lvl - 1);
                prev[lvl-1] = prev[lvl];
            }
    }

    lvl = chooseLevel(); // generate randomly level for new Ndoe
    newNode  = new SkipListNode<T>;
    newNode->next = new nodePtr[sizeof(nodePtr) * (lvl+1)];
    newNode->key = key;
    for(i = 0; i<=lvl; i++) {
        *(newNode->next + i) = curr[i];
        if(prev[i] == 0)
            root[i] = newNode;
        else *(prev[i]->next+i) = newNode;
    }
}
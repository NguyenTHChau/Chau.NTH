#include<iostream>
using namespace std;
class absList
{
protected:
    int dataID;
public:
    absList(int pId=0){
        dataID = pId;
    }
    virtual ~absList(){}
    int getData(){
        return dataID;
    }
    virtual absList* addFirst(int pId) = 0;
    virtual absList* getSubItem() = 0;
    virtual void showAll(ostream&) = 0;
    virtual int countAll(){
        return 0; 
    }
};

class simpleList : public absList
{
public:
    simpleList(int pId):absList(pId){}
    virtual absList* addFirst(int pId){
        dataID = pId;
        return this;
    }
    virtual absList* getSubItem(){
        return NULL; 
    }
    virtual void showAll(ostream& outDev) {
        outDev << dataID << " ";
    }
    virtual int countAll(){
        return 1;
    }
};

class linearList:public absList
{
    absList* subLst;
public:
    linearList(int pId):absList(pId){
        subLst = NULL;
    }
    virtual ~linearList(){
        if(subLst !=NULL)
            delete subLst;
    }
    virtual absList* addFirst(int pId){
        linearList *Lst = new linearList(pId);
        Lst->subLst = this;
        return Lst;
    }
    virtual absList* getSubItem(){
        return subLst;
    }
    virtual void showAll(ostream& outDev) override{
        absList* current = this;
        while(current != NULL){
            outDev << current->getData() << " ";
            current = current->getSubItem();
        }
        outDev << endl;
    }
    virtual int countAll() override{
        if(subLst != NULL){
            return 1 + subLst->countAll();
        }
        else{
            return 1;
        }
    }
};

void main()
{
    simpleList *sLst = new simpleList(-13);
    absList *lnkLst = new linearList(37);
    for (int i = 1; i <= 8;i++){
        lnkLst = lnkLst->addFirst(i*i-7*i);
    }
    delete lnkLst;
}
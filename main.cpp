#include <iostream>

//using namespace std;

namespace mylib
{
    template <typename T>
    class node{
        public:
        T element;
        node *next;
        node(T elemval, node* nextval=nullptr): element(elemval),next(nextval) {}
                node(node* nextval = nullptr) : next(nextval) {}
    };

    template <typename T>
    class list{
    private:
        node<T>* head;
        node<T>* fence;
        node<T>* tail;

        void init()
        {
            head = fence = tail = new node<T>(nullptr);
        }
    public:
        int flag=1;
        list() {init();}
        bool append(T it)
        {
            tail->next = new node<T>(it,nullptr);
            if(flag==1) {head=tail->next;flag++;fence=head;}
            tail = tail->next;
            return true;

        }

        bool print()
        {
          fence=head;
            while(fence!=nullptr)
            {
                std::cout << fence->element << " ";
                fence = fence->next;
            }
            fence=head;
            std::cout<<std::endl;
            return true;
        }

        list(const std::initializer_list<T> arr)
        {
            for(auto it=arr.begin();it<arr.end();it++)
            {
                if(flag==1){
                        head = new node<T>(*it,nullptr);
                        tail=head;
                        fence=head;
                        flag++;
                }
                else{
                        append(*it);

                }
            }
        }


    };
}


int main()
{

    mylib::list<int> l1;
    mylib::list<int> l2={23,5,76,6};

    l1.append(34);
    l1.append(4);
    l1.append(24);
    l1.append(2);

    l1.print();
    l2.print();

    return 0;
}

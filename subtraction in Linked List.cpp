class Solution {
public:
    int reverse(Node* &head){
        Node *temp = head , *nn = NULL , *n1;
        int cnt=0;
        while(temp != NULL){
            n1 = temp -> next;
            temp -> next = nn;
            nn = temp;
            temp = n1;
            cnt++;
        }
        head = nn;
        return cnt;
    }
    Node* solver(Node* head1 , Node* head2){
        Node* temp = NULL;
        Node *t1 = head1 , *t2 = head2;
        int b = 0;
        while(t1 != NULL and t2 != NULL){
            Node *nn = new Node(0);
            int x = (t1 -> data) + b;
            b = 0;
            if((x - (t2 -> data)) < 0){
                x += 10;
                b = -1;
            }
            nn -> data = x - (t2 -> data);
            nn -> next = temp;
            temp = nn;
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        while(t1 != NULL){
            Node *nn = new Node(0);
            nn -> data = (t1 -> data) + b;
            b = 0;
            if((nn -> data) < 0){
                (nn -> data) += 10;
                b = -1;
            }
            nn -> next = temp;
            temp = nn;
            t1 = t1 -> next;
        }
        return temp;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1 -> data == 0 and head1 -> next != NULL){
            head1 = head1 -> next;
        }
        while(head2 -> data == 0 and head2 -> next != NULL){
            head2 = head2 -> next;
        }
        int cnt1 = reverse(head1);
        int cnt2 = reverse(head2);
        if(cnt2 > cnt1){
            swap(head1 , head2);
        }
        else if(cnt1 == cnt2){
            Node *temp = head1 , *temp2 = head2;
            int n1 = 0, n2 = 0;
            while(temp != NULL){
                if((temp -> data) > (temp2 -> data)){
                    n1 = 1;
                    n2 = 0;
                }
                else if((temp -> data) < (temp2 -> data)){
                    n1 = 0;
                    n2 = 1;
                }
                temp = temp -> next;
                temp2 = temp2 -> next;
            }
            if(n2 > n1) swap(head1 , head2);
        }
        Node *ans = solver(head1 , head2);
        while(ans -> data == 0 and ans -> next != NULL){
            ans = ans -> next;
        }
        return ans;
    }
};

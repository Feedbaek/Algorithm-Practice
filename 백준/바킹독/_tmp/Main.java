import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      MyLinkedList list = new MyLinkedList();
      String str = br.readLine();
      int n = Integer.parseInt(br.readLine());

      for(int i=0; i<str.length(); i++)
         list.InsertNode(str.charAt(i));

      for(int i=0; i<n; i++){
         String[] strs = br.readLine().split(" ");
         if(strs[0].equals("L")){
            list.ToLeft();
         }
         else if(strs[0].equals("D")){
            list.ToRight();
         }
         else if(strs[0].equals("B")){
            list.DeleteNode();
         }
         else if(strs[0].equals("P")){
            list.InsertNode(strs[1].charAt(0));
         }
      }

      list.PrintList();
      br.close();
   }
}

class MyLinkedList{
   Node headNode = null;
   Node currentNode = null;

   void InsertNode(Character data){   // currentNode와 currentNode.nextNode 사이에 삽입
      if(headNode==null){
         Node newNode = new Node(data, null, null);

         headNode = newNode;
         currentNode = newNode;
      }
      else{
         Node newNode = new Node(data, null, null);

         if(currentNode!=null){
            newNode.prevNode = currentNode;
            newNode.nextNode = currentNode.nextNode;
            if(currentNode.nextNode != null){
               currentNode.nextNode.prevNode = newNode;
            }
            currentNode.nextNode = newNode;
            currentNode = newNode;
         }
         else{
            headNode.prevNode = newNode;
            newNode.nextNode = headNode;
            headNode = newNode;
         }
      }
   }

   void DeleteNode(){               // currentNode 삭제
      if(currentNode==null)
         return;

      if(currentNode.prevNode != null)
         currentNode.prevNode.nextNode = currentNode.nextNode;
      if(currentNode.nextNode != null)
         currentNode.nextNode.prevNode = currentNode.prevNode;

      // if(currentNode.prevNode != null){
      //    if(currentNode == headNode)
      //       headNode = currentNode.prevNode;
      // }
      // else{
      if(currentNode == headNode)
         headNode = currentNode.nextNode;
      currentNode = currentNode.prevNode;
   }

   void ToLeft(){
      if(currentNode != null)
         currentNode = currentNode.prevNode;
   }

   void ToRight(){
      if(currentNode == null)
         currentNode = headNode;
      else{
         if(currentNode.nextNode != null)
            currentNode = currentNode.nextNode;
      }
   }

   void PrintList() throws Exception {
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      Node tempNode = headNode;

      while(tempNode != null){
         bw.write(Character.toString(tempNode.data));
         tempNode = tempNode.nextNode;
      }
      bw.close();
   }
}

class Node{
   Character data = null;
   Node nextNode = null;
   Node prevNode = null;

   Node(Character data, Node prevNode, Node nextNode){
      this.data = data;
      this.prevNode = prevNode;
      this.nextNode = nextNode;
   }
}

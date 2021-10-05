import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class MaheshSolution{
    public static int startRow,startCol,destRow,destCol,count=0;
    public static Map<Integer,Boolean> visited= new HashMap<Integer,Boolean>();
    public static Deque<Integer> trace= new LinkedList<Integer>();
    public static Map<Integer,Deque<Integer>> ans= new HashMap<Integer,Deque<Integer>>();//18->18,35,52

    static public Boolean checkIfElementPresent(int element) { //check if element is already present in trace//element->35
        if(visited.containsKey(element)){
            if(element!=trace.getLast()&&ans.containsKey(element)&&count<10) {
                Iterator<Integer> iteratorVals=trace.descendingIterator();
                while (iteratorVals.hasNext()) {
                    System.out.print(iteratorVals.next()+" ");
                }
                iteratorVals=ans.get(element).iterator();
                while (iteratorVals.hasNext()) {
                    System.out.print(iteratorVals.next()+ " ");
                }
                System.out.println();
                count++;
                return true;
            }
        }
        return visited.containsKey(element);
    }

    static public Boolean checkIfMoveValid(int currRow,int currCol, int nextRowMove,int nextColMove){
        if(currRow+nextRowMove<=8&&currRow+nextRowMove>=1&&currCol+nextColMove<=8&&currCol+nextColMove>=1&&!checkIfElementPresent((currRow+nextRowMove-1)*8+currCol+nextColMove)) return true;
        return false;
    }

    static public void printPath(int currRow,int currCol){
    if(count>=10) return;
    if(currRow==destRow&&currCol==destCol) {
        trace.addFirst((currRow-1)*8+currCol); //pushing the current element at the top of the stack.
        Iterator<Integer> iteratorVals=trace.descendingIterator();
        while (iteratorVals.hasNext()) {
            System.out.print(iteratorVals.next()+" ");
        }
        System.out.println();
        iteratorVals=trace.descendingIterator();
        ArrayList<Integer> list=new ArrayList<Integer>(trace);
        Collections.reverse(list); //1 18 35 52;4

        for(int i=0;i<list.size();i++) {//i=0
            List<Integer> subList= list.subList(i,list.size());//subList=list.subList(1,4)->subList=[18,35,53];
            Deque<Integer> subDeque=new ArrayDeque<Integer>(subList);
            ans.put(subList.get(0),subDeque);//18->[18,35,52];
        }
        /*
        ans:{
            1->[1,18,35,52]
            18->[18,35,52]
            35->[35,52]
            52->[52]
        }
        ans:{
            20->[20,30,36]
        }
        */
        trace.pop(); //removing the current element from the top of the stack.
        count++;
        return;
    }
    trace.addFirst((currRow-1)*8+currCol);
    visited.put((currRow-1)*8+currCol, true);
    
    if(checkIfMoveValid(currRow,currCol,2,1)) printPath(currRow+2,currCol+1);
    if(checkIfMoveValid(currRow,currCol,1,2)) printPath(currRow+1,currCol+2);
    if(checkIfMoveValid(currRow,currCol,2,-1)) printPath(currRow+2,currCol-1);
    if(checkIfMoveValid(currRow,currCol,1,-2)) printPath(currRow+1,currCol-2);
    if(checkIfMoveValid(currRow,currCol,-1,2)) printPath(currRow-1,currCol+2);
    if(checkIfMoveValid(currRow,currCol,-1,-2)) printPath(currRow-1,currCol-2);
    if(checkIfMoveValid(currRow,currCol,-2,1)) printPath(currRow-2,currCol+1);
    if(checkIfMoveValid(currRow,currCol,-2,-1)) printPath(currRow-2,currCol-1);
    visited.put(trace.pop(),false);
}

    static public void solve(){
        int start,destination;
        Scanner in=new Scanner(System.in);
        start=in.nextInt();
        destination=in.nextInt();
        if(start>64||start<1||destination>64||destination<1||start==destination) {
            System.out.println("No paths possible\n");
        }
        else{
            startRow=(start-1)/8+1; //start=1,destination=64
            startCol=(start-1)%8+1;
            destRow=(destination-1)/8+1;
            destCol=(destination-1)%8+1;
            printPath(startRow,startCol);
        }
        in.close();
    }

    public static void main(String[] args) {
        solve();
    }
}
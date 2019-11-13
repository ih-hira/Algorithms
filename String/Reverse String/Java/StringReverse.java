public class StringReverse{

     public static void main(String []args){
        String str = "inside code";
        str = new StringBuilder(str).reverse().toString();
        System.out.println(str);
     }
}
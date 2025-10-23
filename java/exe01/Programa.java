import java.util.Scanner; 

public class Programa {
    private static Scanner read;

    public static void main(String[] args){
        double toPay;
        double purchaseValue, discount = 0.0;


        read = new Scanner (System.in) ;

        System.out.println("Enter the purchase value: ");

        purchaseValue = read.nextDouble();

        if (purchaseValue >= 100) {
            discount = purchaseValue * 0.20;
            
        } // End if (purchaseValue >= 100)


        System.out.println("The discount is: " + discount);

        toPay = purchaseValue - discount;
        System.out.println("The total to pay is: " + toPay);

    }
}
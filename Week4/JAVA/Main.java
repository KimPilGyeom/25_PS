import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Main ps = new Main();
        ps.j015();
    }
    public void j011(){
        int height, weight;
        double bmi;

        Scanner sc = new Scanner(System.in);
        height = sc.nextInt();
        weight = sc.nextInt();

        bmi = weight / ((height * 0.01) * (height * 0.01));
        if(bmi >= 25){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
        sc.close();
    }

    public void j012() {
        double m2_area, pyung_area;
        Scanner sc = new Scanner(System.in);

        m2_area = sc.nextDouble();
        pyung_area = m2_area / 3.305;

        System.out.printf("%.1f \n",pyung_area);

        if(pyung_area < 15){
            System.out.println("small");
        }
        else if(pyung_area < 30){
            System.out.println("normal");
        }
        else  if(pyung_area < 50){
            System.out.println("large");
        }
        else {
            System.out.println("huge");
        }
        sc.close();
    }

    public void j013(){
        int kor, eng, math;
        int total = 0;
        double average;

        Scanner sc = new Scanner(System.in);
        kor = sc.nextInt();
        eng = sc.nextInt();
        math = sc.nextInt();
        total = kor + eng + math;
        average = total / 3;

        System.out.printf("%d %.1f \n",total ,average);

        if (kor >= 70){
            System.out.println("Korean - Pass\n");
        }
        else{
            System.out.println("Korean - Fail\n");
        }

        if (eng >= 70){
            System.out.println("English - Pass\n");
        }
        else{
            System.out.println("English - Fail\n");
        }

        if (math >= 70){
            System.out.println("Math - Pass\n");
        }
        else{
            System.out.println("Math - Fail\n");
        }
    }

    public void j014(){
        int income;
        double tax;

        Scanner sc = new Scanner(System.in);
        income = sc.nextInt();

        if (income < 10000000){
            tax = income * 0.095;
        }
        else if(income < 40000000){
            tax = income * 0.19;
        }
        else if(income < 80000000){
            tax = income * 0.28;
        }
        else{
            tax = income * 0.37;
        }

        System.out.printf("%.0f\n",tax);

    }

    public void j015(){
        int num1, num2, num3;
        int max_num, min_num;

        Scanner sc = new Scanner(System.in);
        num1 = sc.nextInt();
        num2 = sc.nextInt();
        num3 = sc.nextInt();

        if(num1 > num2){
            max_num = num1;
            min_num = num2;
        }
        else{
            max_num = num2;
            min_num = num1;
        }

        if(num3 > max_num){
            max_num = num3;
        }
        else if(num3 < min_num){
            min_num = num3;
        }

        System.out.printf("%d %d \n", max_num, min_num);

    }
}
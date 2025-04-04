import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main ps = new Main();
        // ps.j021();
//          ps.j022();
//          ps.j023();
//          ps.j024();
            ps. j025();
    }

    public void j021(){
        int height, weight;
        int people;
        int count =0;
        double bmi;

        Scanner sc = new Scanner(System.in);
        people = sc.nextInt();
        //for 문
        // for(int i=0; i<people; i++){
        //     height = sc.nextInt();
        //     weight = sc.nextInt();
        //     bmi = weight / ((height * 0.01) * (height * 0.01));
        //     if(bmi > 25){
        //         count++;
        //     }
        // }
        //while 문

        int i=0;
        while(i<people){
            height = sc.nextInt();
            weight = sc.nextInt();
            bmi = weight / ((height * 0.01) * (height * 0.01));
            if(bmi > 25){
                count++;
            }
            i++;
        }
       
        System.out.printf("%d\n",count);

        sc.close();
    }

    public void j022(){
        double m2_area, pyung_area;
        int count1=0;
        int count2=0;
        int count3=0;
        int count4=0;

        Scanner sc = new Scanner(System.in);

        for(int i=0; i<10; i++){
            m2_area = sc.nextDouble();
            pyung_area = m2_area / 3.305;

            if(pyung_area < 15){
                count1++;
            }
            else if(pyung_area < 30){
                count2++;
            }
            else  if(pyung_area < 50){
                count3++;
            }
            else {
                count4++;
            }
        }
   
        System.out.printf("small - %d \n",count1);
        System.out.printf("normal - %d \n",count2);
        System.out.printf("large - %d \n",count3);
        System.out.printf("huge - %d \n",count4);

        sc.close();
    }
    public void j023() {
        Scanner sc = new Scanner(System.in);

        int count = sc.nextInt();
        int totalsum = 0;
        double average;

        for (int i = 0; i < count; i++) {
            int number = sc.nextInt();
            totalsum += number;
        }

        average = (double) totalsum / count;

        System.out.printf("%d %.1f\n", totalsum, average);
    }

    public void j024() {
        Scanner sc = new Scanner(System.in);

        int[] numbers = new int[10];
        for (int i = 0; i < 10; i++) {
            numbers[i] = sc.nextInt();
        }

        int first = Integer.MIN_VALUE;
        int second = Integer.MIN_VALUE;
        int second_max_index = -1;

        for (int i = 0; i < 10; i++) {
            if (numbers[i] > first) {
                second = first;
                first = numbers[i];
            } else if (numbers[i] > second && numbers[i] < first) {
                second = numbers[i];
            }
        }

        for (int i = 0; i < 10; i++) {
            if (numbers[i] == second) {
                second_max_index = i;
                break;
            }
        }

        System.out.printf("[%d] %d\n", second_max_index, second);
    }

    public void j025() {
        Scanner sc = new Scanner(System.in);

        int[] monthdays = {31,28,31,30,31,30,31,31,30,31,30,31};
        int month = sc.nextInt();
        int day = sc.nextInt();

        if (month < 1 || month > 12 || day < 1 || day > monthdays[month - 1]) {
            System.out.println("Wrong date!");
            return;
        }

        int day_count = 0;
        for (int i = 0; i < month - 1; i++) {
            day_count += monthdays[i];
        }
        day_count += day;

        System.out.println(day_count);
    }
}
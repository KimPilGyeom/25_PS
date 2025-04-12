import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main ps = new Main();

//        ps.j031();
//        ps.j1000();
//        ps.j032();
//        ps.j033();
//        ps.j034();
        ps.j035();
    }

    public void j031() {
        String userid;
        String password;
        String name;

        Scanner sc = new Scanner(System.in);
        userid = sc.nextLine();
        password = sc.nextLine();
        name = sc.nextLine();
        if (password.length() < 3) {
            System.out.printf("Error! password is too short\n");
        } else {
            System.out.printf("User ID: %s", userid);
            System.out.printf("\nPassword: %s", password);
            System.out.printf("\nUser Name: %s\n", name);

        }
    }

    public void j1000() {
        int hour;
        int min;
        int count = 0;

        for (hour = 0; hour < 24; hour++) {
            for (min = 0; min < 60; min++) {
                String mins = Integer.toString(min);
                String hours = Integer.toString(hour);
                if (mins.contains("3") || hours.contains("3")) {
                    count++;
                }
            }
        }
        System.out.printf("%d\n", count);
    }

    public void j032(){
        String str;
        String reverse;

        Scanner sc = new Scanner(System.in);
        str = sc.nextLine();

        StringBuilder sb = new StringBuilder(str);
        reverse = sb.reverse().toString();

        System.out.println(reverse);
    }

    public void j033() {
        int count;
        String name;
        String longest = "";
        String shortest = null;

        Scanner sc = new Scanner(System.in);
        count = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < count; i++) {
            name = sc.nextLine();

            if (i == 0) {
                longest = name;
                shortest = name;
            } else {
                if (name.length() > longest.length()) {
                    longest = name;
                }
                if (name.length() < shortest.length()) {
                    shortest = name;
                }
            }
        }

        System.out.printf("Longest: %s\n", longest);
        System.out.printf("Shortest: %s\n", shortest);
    }

    public void j034(){
        String[] usernames = {"Kim", "lee", "park", "hong", "choi"};
        String[] passwords = {"1111", "1234", "3456", "3535", "7777"};
        String id, pw;

        Scanner sc = new Scanner(System.in);
        id = sc.nextLine();
        pw = sc.nextLine();

        for(int i = 0; i < 5; i++){
            if(id.equals(usernames[i])){
                if(pw.equals(passwords[i])){
                    System.out.printf("Login OK!\n");
                } else {
                    System.out.printf("Incorrect Password!\n");
                }
                return;
            }
        }

        System.out.printf("No User!\n");
    }

    public void j035(){
        int y,m,d,cal;
        String date;

        Scanner sc = new Scanner(System.in);

        date = sc.nextLine();
        cal = Integer.parseInt(date);
        y = cal/10000;
        m = (cal - (y*10000))/100;
        d = (cal - (y*10000))%100;
        y = y/1000 + (y/100)%10 + (y/10)%10 + y%10;

        System.out.println(y+m+d);
    }
}
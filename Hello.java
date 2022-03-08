public class Hello extends Thread {
    public void run() {

        for(int h=1; h <= 3;h++) {
            try {
                Thread.sleep(10);
            }
            catch(Exception hackerearth) {
                System.out.println("hello");
            }
            System.out.print(h+" ");
        }    
    }
    public static void main(String args[]) {
        Hello h1=new Hello();
        Hello h2=new Hello();
        h1.start();
        try {
            h1.join();

        } catch(Exception hackerearth) {
            System.out.println("h1");
        }
        h2.start();
    }

}
import java.time.LocalTime;

import javax.swing.text.Style;

class Interprocess{
    public static int shared=0;
    public static class Response implements Runnable{

        @Override
        public void run() {
            System.out.println("Response:");
            while(shared==0){
                Thread.onSpinWait();
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
                System.out.println("waiting ");
            }
            System.out.println(LocalTime.now());
            
        }

    }
    public static class Request implements Runnable{

        @Override
        public void run() {
            System.out.println("tell the time now ");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            shared=1;
            
        }
        
    }
    public static void main(String[] args) {
        Request request=new Request();
        Response response=new Response();
        Thread rqst=new Thread(request);
        Thread resp=new Thread(response);
        rqst.start();
        resp.start();
    }
}
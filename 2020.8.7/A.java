import java.util.Scanner;
import java.math.BigInteger;
public class Main{
    static BigInteger jc[] = new BigInteger[100001];
    static int b[] = new int[100001];
    static int bb[] = new int[100001];
    static void solve(){
        jc[0]=BigInteger.valueOf(1);
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        //int n=100000;
        BigInteger k = cin.nextBigInteger();
        //BigInteger k = BigInterger.vauleOf(10000);
        for(int i=1;i<n;i++){
            BigInteger ii = BigInteger.valueOf(i);
            jc[i]=jc[i-1].multiply(ii);
            if(i>=6000)break;
        }
        //System.out.println(jc[n-1]);
        k=k.subtract(BigInteger.valueOf(1));
        int tot=0;
        for(int i=n-1;i>=0;i--){
            int q=0,x=0;
            if(i<6000){
                BigInteger tmp=k.divide(jc[i]);
                int now=tmp.intValue();
                k=k.mod(jc[i]);
                for(int j=1;j<=n;j++){
                    if(bb[j]==0)++q;
                    if(q==now+1){
                        b[++tot]=j;
                        break;
                    }
                }
                bb[b[tot]]=1;
            }
            else{
                break;
            }
        }
       for(int i=1;i<=n;i++){
            if(bb[i]==0){
                b[++tot]=i;
            }
        }
        for(int i=1;i<=n;i++){
            System.out.print(b[i]);
            if(i!=n){
                System.out.print(" ");
            }
        }
        System.out.print("\n");
    }
    public static void main(String[] args){
        solve();
    }
}
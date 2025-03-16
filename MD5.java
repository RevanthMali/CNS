import java.util.*;
import java.security.*;
import java.math.BigInteger;

public class Main {
    public static String encryptMsg(String str) throws Exception {
        MessageDigest md = MessageDigest.getInstance("MD5");
        byte[] messageDigest = md.digest(str.getBytes());
        BigInteger no = new BigInteger(1, messageDigest);
        String hashText = no.toString(16);
        
        // Ensure the hash is 40 characters long
        while (hashText.length() < 40) {
            hashText = "0" + hashText;
        }
        return hashText;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the message:");
        String str = sc.nextLine();
        
        try {
            String hash = encryptMsg(str);
            System.out.println("Hash code generated by SHA-1 for \"" + str + "\" is: " + hash);
        } catch (Exception e) {
            System.out.println("An error occurred while generating the hash: " + e.getMessage());
        }
    }
}

// input: rohit sharma
// output: 69586FBC663EEA985BC379BB558224C3

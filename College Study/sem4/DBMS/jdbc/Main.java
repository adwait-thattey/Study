import java.sql.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello");

        try {
            String connUrl = "jdbc:postgresql://localhost:15000/flyhigh";

            Class.forName("org.postgresql.Driver");

            Connection conn = DriverManager.getConnection(connUrl, "admin", "minda");

            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("select * from users;");

            while (rs.next()) {
                System.out.println(rs.getString(1) + " " + rs.getString(2) + " " + rs.getString(3) + " "
                        + rs.getString(4) + " " + rs.getString(5));
            }
            conn.close();

        } catch (SQLException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
        }
    }
}
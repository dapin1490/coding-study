import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val token = StringTokenizer(br.readLine())
    var score = token.nextToken().toInt()
    
    when (score) {
        in 90..100 -> bw.write("A\n")
        in 80..89 -> bw.write("B\n")
        in 70..79 -> bw.write("C\n")
        in 60..69 -> bw.write("D\n")
        else -> bw.write("F\n")
    }
    
    bw.flush()
    bw.close()
    br.close()
}

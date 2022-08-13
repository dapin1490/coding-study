import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

fun main() {
	val br = BufferedReader(InputStreamReader(System.`in`))
	val bw = BufferedWriter(OutputStreamWriter(System.out))

	val n: Int = br.readLine().toInt()
	var str1: String; var str2: String

	repeat(n) {
		val token = StringTokenizer(br.readLine())
		str1 = token.nextToken()
		str2 = token.nextToken()

		bw.write("$str1 & $str2 are ${if (isAnagram(str1, str2)) "anagrams." else "NOT anagrams."}\n")
	}

	bw.flush()
	bw.close()
	br.close()
}

fun isAnagram(str1: String, str2: String): Boolean {
	val abc1 = Array<Int>(26) { 0 }
	val abc2 = Array<Int>(26) { 0 }
	val len: Int

	if (str1.length == str2.length)
		len = str1.length
	else
		return false

	for (i in 0 until len) {
		abc1[str1[i].code - 'a'.code]++
		abc2[str2[i].code - 'a'.code]++
	}

	for (i in 0 until 26) {
		if (abc1[i] != abc2[i])
			return false
	}

	return true
}

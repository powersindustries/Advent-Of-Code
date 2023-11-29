#include "Day6.h"
#include <iostream>
#include <unordered_map>

#define MARKER_SIZE_P1 4
#define MARKER_SIZE_P2 14


// ----------------------------------------------------------------
// ----------------------------------------------------------------
Day6::Day6()
{
    m_sPacket = "qhbhzbzzfrzrbzzcjzjrrvcvrvqvvnggnngcgssswbblplrlflfnnnmmjppgddqndnrnlnccpfcfjcjvjdjqqqmhhmwhwmmsnsvsjvjnvjnvjvsjsmjsjccwcqwcqwqjqwjwmwbmmbzbsbvsslbsbbbntnvvphpqqvrrtbrtrfftppbggpzzfhfcfsfmssffmbmzzmqzzblzzzmwwnggjwgjwgjgpgmmjvvmcvmmcfchfhllwmlljqqldqdqttsgsvscsmsnsmstmtssvgsgddwdffbppwfpplhlchhhdvvdrrmttmptmmmjsmshmmmgqmgggzjgzzmwzwcwhchqqfpfvvbqvbqbrblrrmtmstmmjvmmdnmmzczdzpztppjhjjwzjjjtdjjpljpjcppjllsffhbffbhhgttqjqzzfzbzcbzcbcrrjjrwrgwwbcbpcccctrtqtfqqfjjpgpdgdfgfrggpjjljglgclcqcqmcqmmgjjllpmphpjjgfjjqrrbppwmpmccftctjtjgjtgggzffcggwzzzdjdzzlgzgjzzvqvppczzjnjvvfhhtwtttdwtdtvddpzpnpcnppmvmcmcsmstthctchcggtssdttvztvvldlfftqqbzzjttvzztppscctzccgmcmvmhhchcscbbshbssgwwthwhmwwcgwcwrrvrzvrzzzvhvdvmmprrdmrmfmrmbmjbbmqbmbqqhbbszsjjlqjljtjstshhgphpffdhhtggtgbbqcqgqccfffcpcbpbfppwqpqcclbbwdwsscpchhfpfmpfmflfnnmggwrrznnghgvhhghrrhwrrcschcscqcmcfcvvgzztjtqjjshspsqsmmjnnmttsshvhmmqfqzztbzttvhttmwttnqnfncfcpfflmllmtlmmphmhlmmltmtztcczhzbbfmmlglnnfpppqplljwjfwfdwdzwddszddqzqnzzzwwlzzqvvjlllrwlrrmpmrmbmpplpspqsqmqcmcjjshsvstvvwtvthvvrfvvqmmjpmjmrjmmlvvnnrjjrcrwrhwwqzzvgvngncgcqqcffmfzfssbnbfblbggwhggmtgtvvqhhpttbcbczcjjbqbhqbhqbbccbhbqhbbmppdlpdllbvvdpvdvwvsvppllgblbttmcmtccbsswmswwwzfwfhhtfhthctchcfhhhfjjvhjhgjjjcwjwggrtgrttcqcwcswccfdffvpvtptprrvjjqvjjghggshhwmmcscmsmhmvmppprfrwwrhhvghhtnhncctbbbwzzbgzgdzgdzdpdvpvbbwgbwwrqwrqwqbqvvclccfcfzfdfrrthrrqcqddplpqlppbbfrfmmrmnnwhhgddmwwrzrsswpwhwdwhhsmhshqsqllbvlbllwbwbpwwfwmwsmspsvsdsbscctpctppvvpggtjjdmdqqgqbgglccvzcvcnczcgzgmzznpzzpcpnpvpcvvffrttqrqttflfbfjfnnwnlwlhwwqzqnqfftstdsttglldwwgqwwvqqzczfzdffbfsfssfwswdwnwdnnbcncwctttvsvjsvsrvvbtvvzhhvjvtvtjtsjjvhjjwpjjnzzpczzppgcpgcpgcgsgvsgvsscrcpcpspllzvzddpssssdpsddhffllzmzhzfhhdvhhvbvwwpwqpwqpwwmvwmvwvgvmvpvmpmrmzrrblltjtggvnggvppthhzjhzhffrvrhvrhrlrslsflfhhtvhvmmhppjgpjpcccmqcqvqhvvfssrtmnwjjslwhjgpvrwspjlwdwrmvfgwmplrmjrllndrjzvjfbwvzpjpfqrnjspwcpsgcvdlmfdfrvwdcvmbrnzncgnqlcvgqtpsbbpvprncdsgvpqbpcnffwqmmfsvnzspchhrlnzbhcdfdgtsllmqfbrcqwbmmzrfvsghjpmrndsdbqvtprmblnbvbnpvhtphbpjwdssvwgdzwztbpzdcsqzldjzrgcwhhspblrtncvntppcgttlflflnntcnzpbpgsclcjvbjhldcdzwjjhnfwzjmgcwtljhvbncwqnjhbrhfqcmnsdvntsbgnpqttzvbhzzpdznrhjpnsqzsztsblstbghlpwbmqjctlnqnttwshfvmjdhgbgjdhbzrfjqndrrhlqcmplczjtwpstlsmwwzqzmgvhsvjgbrtfwmvwlbhpccbqvmfmlgmbmbmldbcwmmhpnnbnffbnqgwhclgpzgbpjqvzmqhhhpltnwrdfrrnmlfrzflpnjztlnfzzzgmncprtblpsvrqgrnzbzfzhzhjjjdrnpvjpnwmlmlgvvtqmdvpnhvcrdmthcnnnvhnzmvgrtdvcthgjtvcgmtpsvmfztrflrrzbmcfhftwwcnjfpjtsnzjccmvdnrrwvbfjgcjttdvzncqhlqqphwphclztbhlqcfmnhcjmsscplnrsjqpdzrrzbthbcdnrzgdmstpgqqsvzclvmzjjdfqhhhttwcjtmwcbltghmslqvltqbjqqjpjvgntvnlttjcnhltflglgsmjwjjfldpfgjgrhttbwfhpsdbsmsfmfbtjlnhvjfqjrqhwdrcwpfthdgqzjjjfcvgdffrhvvwzfghpszmjjgscjvjnlgnbfbgfrbbzbzbnzngthrddfmsgsqqdddpfqwlchfblrvjdcgnzfzwmmnmvnzmpfmhbbhsbfdfclzcnbrlgpbsvfgfpshrpvpgccmmghphrcvzwnlqjcfwrtwvlvcsdldldvnpwgrcsqlftllcctnvcwbdswvqlzwzzbpmvvctcrgnjfstbqvnzczrjlljfqzrwtfwmlvvdfbfntrrljtbrtbdfsqpnppfbppbsmghbnqddhrvwmgzttnqjrqlfrdhqjndmnjlbctgclltmznmrqtfjsjwnztdvhnhlfwpnnqlhhsrfzglsnrdnfvrqssbtlthzfnjdvrcgzsbnpdgqhhrlwspfqfqpvzdfwgrlhwplzvbzprsqzcwvhggvzpgjztnvwvddsflgsvqljmmhhdzqsqmthwzvllqwmsnvdpdbjcgdtrsnmwhnzhbhgjssstmhrpssnhnntmrbbbjgmjqtncbdljcgtmbctpgdrnqcnrpssrdtpbsmlzlcztbrggglswnjzqgbsmgbqdzppqrwgtnlrjrvlpnqlcdwhltzzlqdwwrglldzcqrjtjtlgdqrtwzjgtdthsdccsmsrbjjsgdqcwdltvnjwtddsnpnsvzcdbfqnvsjbngqrztmbrnbvhhjzdtqrgldpvjqjpnshbjdsdgbjdjzdmrvzhwmtgcjrfnprstqgfgnwfpcjzhlnwpdbtqbspssqdrzhmmsrqtlwngvbrvgdgztnrlwcnqwvcdmhhdrmpfqbgbjpvzwbsbgcpsnpjplcrjdhflqvsdctclqqnmprngtvbmlmpqrsqdsrzgsmzmsczpsnmfmtfnjvnddjhqbjdvtgftjfvjhgpjqdhlszqjmcbnwrppzwjvmgblspjmfhjdbnmrllnfqlpcbndvqdzhhmmrpsljgdshpnrgnmwfjsdncqcwlctccrqghfdbsqqbnwctcqpvlrqqqvdjwlcnzmvdmcvlwnftjnqqldfwhmdtcpnlgfcdjdrfvmwqdzsjzctmmmrswhlwthttvcsqqscdcsmjgqfjhswlpsfjrppdmbwrthcwszqwwgnjsdqdrswmnzbrvqcwlrlwwvjmrrhsnzprggbzhhdqwvnspsmzzqdtbphzvwrzvqnbntjndrwllzwchczdwvnfjjdwfhdlgncftldzwdtjzjrmnfwwgmqdrltmgrfsjztfcvwjsggtvbnsvthflwfdtljrgqhmfqhmhfffqhtgwtlmwgzsglqnfwnrnvgvbdgqjrqtsmgsmzdpffnnzwlpbqphqmgdzspfrdqlptwmfwlgnqqdhtbbjtfhllrhhdcszjtmrprzhzzlgjqbcnhzcmhzrsnmmrzztffrldthhfvwhgjhwmjfbdvnllfmlpdsldjnpcwlpbwqzdwbgjb";
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day6::Part1()
{
    return FindMarker(MARKER_SIZE_P1);
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day6::Part2()
{
    return FindMarker(MARKER_SIZE_P2);
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day6::FindMarker(const int inMarkerSize)
{
    const int sPacketSize = static_cast<int>( m_sPacket.size() );
    for (int x = 0; x < sPacketSize; ++x)
    {
        std::unordered_map<char, int> searchMap;
        searchMap.insert({ m_sPacket[x], 1 });

        for (int y = x; y < x + inMarkerSize; ++y)
        {
            char cCurrChar = m_sPacket[y];
            if (searchMap.find(cCurrChar) == searchMap.end())
            {
                searchMap.insert({cCurrChar, 1});
            }
        }

        if (searchMap.size() == inMarkerSize)
        {
            return x + inMarkerSize;
        }
    }

    return 0;
}

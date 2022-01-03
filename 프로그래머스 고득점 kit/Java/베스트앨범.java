import java.util.*;

class Solution {

    static class Music {
        String genre;
        int play;
        int idx;

        public Music(String genre, int play, int idx) {
            this.genre = genre;
            this.play = play;
            this.idx = idx;
        }
    }

    public int[] solution(String[] genres, int[] plays) {
        Map<String, Integer> genrePlay = new HashMap<>();
        int[] answer;

        for (int i = 0; i < genres.length; i++) {
            genrePlay.put(genres[i], genrePlay.getOrDefault(genres[i], 0) + plays[i]);
        }

        List<String> genreKeySet = new ArrayList<>(genrePlay.keySet());
        Collections.sort(genreKeySet, (value1, value2) -> (genrePlay.get(value2).compareTo(genrePlay.get(value1))));

        List<Music> result = new ArrayList<>();

        for (String genre : genreKeySet) {
            List<Music> tmp = new ArrayList<>();
            for (int i = 0; i < genres.length; i++) {
                if (genres[i].equals(genre)) {
                    tmp.add(new Music(genre, plays[i], i));
                }
            }

            Collections.sort(tmp, (o1, o2) -> o2.play - o1.play);
            result.add(tmp.get(0));
            if (tmp.size() != 1) {
                result.add(tmp.get(1));
            }
        }

        answer = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i).idx;
        }

        return answer;
    }
}
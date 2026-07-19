class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> m = new HashMap<>();

        for(String str: strs){
            char[] c_str = str.toCharArray();
            Arrays.sort(c_str);
            String key = new String(c_str);

            m.putIfAbsent(key, new ArrayList<String>());
            m.get(key).add(str);
        }

        return new ArrayList<>(m.values());
    }
}
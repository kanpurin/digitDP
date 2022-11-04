#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct PartitionRefinement {
    std::unordered_map<int,std::unordered_set<int>> block;
    std::vector<int> block_id;
    int t;

    PartitionRefinement(int k) : block_id(k) {
        for (int i = 0; i < k; i++) {
            block[0].insert(i);
            block_id[i] = 0;
        }
        t = 1;
    }
    
    std::vector<std::pair<int,int>> partition(std::vector<int> &v) {
        std::unordered_map<int,int> split;
        for (int i = 0; i < v.size(); i++) {
            if (block[block_id[v[i]]].size() == 1) {
                if (split.find(block_id[v[i]]) == split.end()) continue;
                // 元に戻す
                for (int p : block[split[block_id[v[i]]]]) {
                    block_id[p] = block_id[v[i]];
                    block[block_id[v[i]]].insert(p);
                }
                block.erase(split[block_id[v[i]]]);
                continue;
            }
            block[block_id[v[i]]].erase(v[i]);
            if (split.find(block_id[v[i]]) != split.end()) {
                block_id[v[i]] = split[block_id[v[i]]];
                block[block_id[v[i]]].insert(v[i]);
            }
            else {
                split[block_id[v[i]]] = t;
                block_id[v[i]] = t++;
                block[block_id[v[i]]].insert(v[i]);
            }
        }
        std::vector<std::pair<int,int>> res;
        for (auto p : split) {
            res.push_back(p);
        }
        return res;
    }
};
#include "common.h"

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


bool check(Natural prime1, Natural prime2, common::Primes& primes)
{
    auto digit1 = common::toDigits(prime1, 10);
    auto digit2 = common::toDigits(prime2, 10);

    auto digit1Copy = digit1;
    for (auto d: digit2) {
        digit1Copy.push_back(d);
    }
    if (not primes.contain(common::fromDigits(digit1Copy, 10))) {
        return false;
    }
    for (auto d: digit1) {
        digit2.push_back(d);
    }
    return (primes.contain(common::fromDigits(digit2, 10)));
}


class Graph
{
public:
    Graph() {}

    void add(Natural n1, Natural n2)
    {
        addOneDirection(n1, n2);
        addOneDirection(n2, n1);
    }

    std::set<Natural> adjacent(Natural n) const
    {
        auto it = graph_.find(n);
        if (it == graph_.end()) {
            return {};
        }
        return it->second;
    }

    bool check(Natural n1, Natural n2) const
    {
        auto it = graph_.find(n1);
        if (it == graph_.end()) {
            return false;
        }
        return it->second.find(n2) != it->second.end();
    }

private:
    void addOneDirection(Natural begin, Natural end)
    {
        auto it = graph_.find(begin);
        if (it == graph_.end()) {
            graph_[begin] = {end};
            return;
        }
        it->second.insert(end);

    }

    std::map<Natural, std::set<Natural>> graph_;
};


bool checkFullSet(const Naturals& primes, const Graph& graph)
{
    for (size_t i = 0; i < primes.size(); ++i) {
        for (size_t j = i + 1; j < primes.size(); ++j) {
            if (not graph.check(primes[i], primes[j])) {
                return false;
            }
        }
    }
    return true;
}

Naturals sizeSubset(const Naturals& primes, size_t size, const Graph& graph)
{
    if (size > primes.size()) {
        return {};
    }
    std::vector<bool> mask(primes.size(), false);
    for (size_t i = primes.size() - 1; i + size >= primes.size(); --i) {
        mask[i] = true;
    }
    do {
        Naturals toCheck;
        for (size_t i = 0; i < mask.size(); ++i) {
            if (mask[i]) {
                toCheck.push_back(primes[i]);
            }
        }
        if (checkFullSet(toCheck, graph)) {
            return toCheck;
        }

    } while (std::next_permutation(mask.begin(), mask.end()));
    return {};
}


Naturals findMaxClique(const Naturals& primes, const Graph& graph)
{
    std::vector<std::set<Natural>> cands;
    for (auto p: primes) {
        cands.push_back({p});
    }

    for (int iter = 1; iter < primes.size(); ++iter) {
        std::vector<std::set<Natural>> nextCands;

        for (const auto& cand: cands) {
            for (auto p: primes) {
                if (cand.count(p) > 0) {
                    continue;
                }
                bool canExtend = true;
                for (auto alreadyInClique: cand) {
                    if (not graph.check(alreadyInClique, p)) {
                        canExtend = false;
                        break;
                    }
                }
                if (canExtend) {
                    std::set<Natural> nextCand(cand);
                    nextCand.insert(p);
                    nextCands.push_back(std::move(nextCand));
                }
            }
        }
        if (nextCands.size() == 0) {
            auto& cand = cands[0];
            return Naturals(cand.begin(), cand.end());
        } else {
            nextCands.swap(cands);
        }
    }
    return {};
}

int main()
{
    common::Primes primes;

    // std::cout << primes.contain(1) << std::endl;
    // std::cout << primes.contain(2) << std::endl;
    // std::cout << primes.contain(37) << std::endl;
    // std::cout << primes[3] << std::endl;
    // std::cout << primes.contain(37) << std::endl;

    // for (int i = 0; i < 10; ++i)
    // {
    //     std::cout << "  " << primes[i] << std::endl;
    // }

    // std::cout << check(7, 109, primes) << std::endl;
    // std::cout << check(673, 109, primes) << std::endl;

    int N = 5;
    Graph graph;

    for (int i = 0; true; ++i) {
        auto prime = primes[i];
        for (int j = 0; j < i; ++j) {
            if (check(prime, primes[j], primes)) {
                graph.add(prime, primes[j]);
            }
        }

        auto adj = graph.adjacent(prime);
        // std::cout << prime << ": " << adj.size() << std::endl;

        auto clique = findMaxClique(Naturals(adj.begin(), adj.end()), graph);
        if (clique.size() == N - 1) {
            // std::cout << prime << ": ";
            // for (auto p: clique) {
            //     std::cout << p << " ";
            // }
            // std::cout << std::endl;

            Natural sum = prime;
            for (auto p: clique) {
                sum += p;
            }
            std::cout << sum << std::endl;
            break;

        }

        // auto subset = sizeSubset(Naturals(adj.begin(), adj.end()), N - 1, graph);
        // if (subset.size() != 0) {
        //     std::cout << prime << ": ";
        //     for (auto p: subset) {
        //         std::cout << p << " ";
        //     }
        //     std::cout << std::endl;

        //     Natural sum = prime;
        //     for (auto p: subset) {
        //         sum += p;
        //     }
        //     std::cout << "sum: " << sum << std::endl;
        //     break;
        // }

    }

    // for (int i = 0; i < 100; ++i) {
    //     auto adj = graph.adjacent(primes[i]);
    //     std::cout << primes[i] << ": ";
    //     for (auto a: adj) {
    //         std::cout << a << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}
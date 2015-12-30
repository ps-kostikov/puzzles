#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <sstream>
#include <algorithm>

enum Suit
{
    SPADES = 1,
    CLUBS,
    DIAMONDS,
    HEARTS
};

enum Rank
{
    TWO = 1,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

struct Card
{
    Rank rank;
    Suit suit;
};

Card parseCard(const std::string& s)
{
    if (s.size() != 2) {
        throw std::runtime_error("wrong string size");
    }
    Rank rank;
    if (s[0] == '2') {
        rank = Rank::TWO;
    } else if (s[0] == '3') {
        rank = Rank::THREE;
    } else if (s[0] == '4') {
        rank = Rank::FOUR;
    } else if (s[0] == '5') {
        rank = Rank::FIVE;
    } else if (s[0] == '6') {
        rank = Rank::SIX;
    } else if (s[0] == '7') {
        rank = Rank::SEVEN;
    } else if (s[0] == '8') {
        rank = Rank::EIGHT;
    } else if (s[0] == '9') {
        rank = Rank::NINE;
    } else if (s[0] == 'T') {
        rank = Rank::TEN;
    } else if (s[0] == 'J') {
        rank = Rank::JACK;
    } else if (s[0] == 'Q') {
        rank = Rank::QUEEN;
    } else if (s[0] == 'K') {
        rank = Rank::KING;
    } else if (s[0] == 'A') {
        rank = Rank::ACE;
    } else {
        throw std::runtime_error("wrong rank symbol");
    }
    Suit suit;
    if (s[1] == 'S') {
        suit = Suit::SPADES;
    } else if (s[1] == 'C') {
        suit = Suit::CLUBS;
    } else if (s[1] == 'D') {
        suit = Suit::DIAMONDS;
    } else if (s[1] == 'H') {
        suit = Suit::HEARTS;
    } else {
        throw std::runtime_error("wrong suit symbol");
    }
    return Card{rank, suit};
}

typedef std::vector<Card> Cards;

struct Hand
{
    Cards cards;
};

enum HandType
{
    HIGH_CARD = 1,
    ONE_PAIR,
    TWO_PAIRS,
    THREE_OF_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH
};

struct CanonicalHand
{
    HandType type;
    std::vector<Rank> orderedRanks;
};

bool isHandLowestStraight(const Hand& hand)
{
    std::vector<Rank> ranks;
    for (auto card: hand.cards) {
        ranks.push_back(card.rank);
    }
    std::sort(ranks.begin(), ranks.end());
    return (
        ranks[0] == Rank::TWO and
        ranks[1] == Rank::THREE and
        ranks[2] == Rank::FOUR and
        ranks[3] == Rank::FIVE and
        ranks[4] == Rank::ACE
    );
}

bool isHandStraight(const Hand& hand)
{
    if (isHandLowestStraight(hand)) {
        return true;
    }
    std::vector<Rank> ranks;
    for (auto card: hand.cards) {
        ranks.push_back(card.rank);
    }
    std::sort(ranks.begin(), ranks.end());
    for (int i = 0; i + 1 < ranks.size(); ++i) {
        if (ranks[i] + 1 != ranks[i + 1]) {
            return false;
        }
    }
    return true;
}

std::vector<Rank> lowestStraighOrderedRanks{
    Rank::FIVE,
    Rank::FOUR,
    Rank::THREE,
    Rank::TWO,
    Rank::ACE,
};

CanonicalHand toCannonicalHand(const Hand& hand)
{
    std::map<Rank, int> ranksMap;
    std::map<Suit, int> suitsMap;
    for (auto card: hand.cards) {
        ++ranksMap[card.rank];
        ++suitsMap[card.suit];
    }

    typedef std::pair<Rank, int> RankNum;
    std::vector<RankNum> rankNums;
    for (auto it: ranksMap) {
        rankNums.emplace_back(it.first, it.second);
    }

    std::sort(rankNums.rbegin(), rankNums.rend(), [](const RankNum& left, const RankNum& right) {
        if (left.second != right.second) {
            return left.second < right.second;
        }
        return left.first < right.first;
    });

    std::vector<Rank> orderedRanks;
    for (auto pair: rankNums) {
        for (int i = 0; i < pair.second; ++i) {
            orderedRanks.push_back(pair.first);
        }
    }

    bool isFlush = suitsMap.size() == 1;
    bool isStraight = isHandStraight(hand);
    bool isLowestStraight = isHandLowestStraight(hand);

    if (isFlush and isStraight) {
        if (orderedRanks[0] == Rank::ACE) {
            return CanonicalHand{ROYAL_FLUSH, std::move(orderedRanks)};
        } else if (isLowestStraight) {
            return CanonicalHand{STRAIGHT_FLUSH, lowestStraighOrderedRanks};
        } else {
            return CanonicalHand{STRAIGHT_FLUSH, std::move(orderedRanks)};
        }
    } else if (rankNums[0].second == 4) {
        return CanonicalHand{FOUR_OF_KIND, std::move(orderedRanks)};
    } else if (rankNums[0].second == 3 and rankNums[1].second == 2) {
        return CanonicalHand{FULL_HOUSE, std::move(orderedRanks)};
    } else if (isFlush) {
        return CanonicalHand{FLUSH, std::move(orderedRanks)};
    } else if (isStraight) {
        if (isLowestStraight) {
            return CanonicalHand{STRAIGHT, lowestStraighOrderedRanks};
        } else {
            return CanonicalHand{STRAIGHT, std::move(orderedRanks)};
        }
    } else if (rankNums[0].second == 3) {
        return CanonicalHand{THREE_OF_KIND, std::move(orderedRanks)};
    } else if (rankNums[0].second == 2 and rankNums[1].second == 2) {
        return CanonicalHand{TWO_PAIRS, std::move(orderedRanks)};
    } else if (rankNums[0].second == 2) {
        return CanonicalHand{ONE_PAIR, std::move(orderedRanks)};
    } else {
        return CanonicalHand{HIGH_CARD, std::move(orderedRanks)};
    }
}

bool less(const CanonicalHand& left, const CanonicalHand& right)
{
    if (left.type != right.type) {
        return left.type < right.type;
    }
    for (size_t i = 0; i < left.orderedRanks.size(); ++i) {
        if (left.orderedRanks[i] != right.orderedRanks[i]) {
            return left.orderedRanks[i] < right.orderedRanks[i];
        }
    }
    throw std::runtime_error("equal hands");
}

Hand parseHand(std::istream& in)
{
    Hand hand;
    std::string part;
    for (size_t i = 0; i < 5; ++i) {
        std::getline(in, part, ' ');
        hand.cards.push_back(parseCard(part));
    }
    return hand;
}

bool check(const std::string& line)
{
    std::stringstream ss(line);
    Hand leftHand = parseHand(ss);
    Hand rightHand = parseHand(ss);
    return less(toCannonicalHand(rightHand), toCannonicalHand(leftHand));
}

int main()
{
    std::string line;
    int count = 0;
    while(std::getline(std::cin, line)) {
        bool leftWins = check(line);
        // std::cout << line << ": " << (leftWins ? "left" : "right") << std::endl;
        if (leftWins) {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
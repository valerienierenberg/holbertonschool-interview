#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list, hot_list=[]):
    """recursive function that queries the Reddit API and
    returns a count of all hot articles for a given subreddit"""
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {
        "User-Agent": "My-User-Agent"
    }
    params = {
        "limit": "100"
    }
    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)
    if response.status_code != 200:
        return 0
    data = response.json()
    children = data.get("data").get("children")
    for child in children:
        hot_list.append(child.get("data").get("title"))
    for word in word_list:
        for hot in hot_list:
            if word in hot:
                return hot_list.count(word)
    return 0

#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list):
    """recursive function that queries the Reddit API and returns
    a count of all hot articles for a given subreddit"""
    response = requests.get('https://www.reddit.com/r/{}/hot.json?limit=100'.
                            format(subreddit), headers={'User-Agent': 'custom'},
                            allow_redirects=False)
    if response.status_code == 404:
        return 0
    else:
        data = response.json()
        posts = data['data']['children']
        count = 0
        for post in posts:
            title = post['data']['title']
            for word in word_list:
                if word in title.lower():
                    count += 1
        if count == 0:
            return 0
        else:
            return count + count_words(subreddit, word_list)

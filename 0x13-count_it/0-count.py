#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list, word_dict={}):
    """count_words"""
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    header = {'User-Agent': 'My User Agent 1.0'}
    response = requests.get(url, headers=header)
    if response.status_code != 200:
        return 0
    data = response.json()
    for post in data.get('data').get('children'):
        title = post.get('data').get('title')
        for word in word_list:
            if word in title:
                if word in word_dict:
                    word_dict[word] += 1
                else:
                    word_dict[word] = 1
    after = data.get('data').get('after')
    if after is None:
        return word_dict
    return count_words(subreddit, word_list, word_dict)

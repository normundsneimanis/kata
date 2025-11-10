use std::thread;
use std::sync::mpsc::channel;
use std::sync::mpsc::Sender;

pub fn main() {
    let content_per_thread = vec!["Hello\nGoodbye", "Wow\nCool\nData!", "a\nb\nc"];
    let (sender, receiver) = channel::<Vec<&str>>();
    concurrent_search("o", content_per_thread, &sender);
    drop(sender);

    for v in receiver.iter() {
        v.iter().for_each(|line| println!("{:?}", line))
    }
}

fn concurrent_search<'a>(
    query: &str,
    content_per_thread: Vec<&'a str>,
    sender: &Sender<Vec<&'a str>>,
) {
    thread::scope(|s| {
        for th_content in content_per_thread {
            s.spawn(move || {
                let matched_lines = search(query, th_content);
                sender.send(matched_lines).unwrap();
            });
        }
    })
}

fn search<'a>(query: &str, content: &'a str) -> Vec<&'a str> {
    content
        .lines()
        .filter(|line| line.contains(query))
        .collect()
}

#include <linux/xattr.h>
#include <linux/overflow.h>
	(IS_ENABLED(CONFIG_SECURITY_LANDLOCK) ? 1 : 0) + \
	(IS_ENABLED(CONFIG_IMA) ? 1 : 0) + \
	(IS_ENABLED(CONFIG_EVM) ? 1 : 0))
 * Fill all of the fields in a userspace lsm_ctx structure.  If @uctx is NULL
 * simply calculate the required size to output via @utc_len and return
 * success.
int lsm_fill_user_ctx(struct lsm_ctx __user *uctx, u32 *uctx_len,
	/* no buffer - return success/0 and set @uctx_len to the req size */
	if (!uctx)
		goto out;

#define call_int_hook(FUNC, ...) ({				\
	int RC = LSM_RET_DEFAULT(FUNC);				\
			if (RC != LSM_RET_DEFAULT(FUNC))	\
	return call_int_hook(binder_set_context_mgr, mgr);
	return call_int_hook(binder_transaction, from, to);
	return call_int_hook(binder_transfer_binder, from, to);
	return call_int_hook(binder_transfer_file, from, to, file);
	return call_int_hook(ptrace_access_check, child, mode);
	return call_int_hook(ptrace_traceme, parent);
	return call_int_hook(capget, target, effective, inheritable, permitted);
	return call_int_hook(capset, new, old, effective, inheritable,
			     permitted);
	return call_int_hook(capable, cred, ns, cap, opts);
	return call_int_hook(quotactl, cmds, type, id, sb);
	return call_int_hook(quota_on, dentry);
	return call_int_hook(syslog, type);
	return call_int_hook(settime, ts, tz);
	return call_int_hook(bprm_creds_for_exec, bprm);
	return call_int_hook(bprm_creds_from_file, bprm, file);
	return call_int_hook(bprm_check_security, bprm);
	return call_int_hook(fs_context_submount, fc, reference);
	return call_int_hook(fs_context_dup, fc, src_fc);
	rc = call_int_hook(sb_alloc_security, sb);
	return call_int_hook(sb_eat_lsm_opts, options, mnt_opts);
	return call_int_hook(sb_mnt_opts_compat, sb, mnt_opts);
	return call_int_hook(sb_remount, sb, mnt_opts);
	return call_int_hook(sb_kern_mount, sb);
	return call_int_hook(sb_show_options, m, sb);
	return call_int_hook(sb_statfs, dentry);
	return call_int_hook(sb_mount, dev_name, path, type, flags, data);
	return call_int_hook(sb_umount, mnt, flags);
	return call_int_hook(sb_pivotroot, old_path, new_path);
	struct security_hook_list *hp;
	int rc = mnt_opts ? -EOPNOTSUPP : LSM_RET_DEFAULT(sb_set_mnt_opts);

	hlist_for_each_entry(hp, &security_hook_heads.sb_set_mnt_opts,
			     list) {
		rc = hp->hook.sb_set_mnt_opts(sb, mnt_opts, kern_flags,
					      set_kern_flags);
		if (rc != LSM_RET_DEFAULT(sb_set_mnt_opts))
			break;
	}
	return rc;
	return call_int_hook(sb_clone_mnt_opts, oldsb, newsb,
	return call_int_hook(move_mount, from_path, to_path);
	return call_int_hook(path_notify, path, mask, obj_type);
	rc = call_int_hook(inode_alloc_security, inode);
	return call_int_hook(dentry_init_security, dentry, mode, name,
			     xattr_name, ctx, ctxlen);
	return call_int_hook(dentry_create_files_as, dentry, mode,
		/* Allocate +1 as terminator. */
		new_xattrs = kcalloc(blob_sizes.lbs_xattr_count + 1,
	return call_int_hook(inode_init_security_anon, inode, name,
	return call_int_hook(path_mknod, dir, dentry, mode, dev);
/**
 * security_path_post_mknod() - Update inode security field after file creation
 * @idmap: idmap of the mount
 * @dentry: new file
 *
 * Update inode security field after a file has been created.
 */
void security_path_post_mknod(struct mnt_idmap *idmap, struct dentry *dentry)
{
	if (unlikely(IS_PRIVATE(d_backing_inode(dentry))))
		return;
	call_void_hook(path_post_mknod, idmap, dentry);
}

	return call_int_hook(path_mkdir, dir, dentry, mode);
	return call_int_hook(path_rmdir, dir, dentry);
	return call_int_hook(path_unlink, dir, dentry);
	return call_int_hook(path_symlink, dir, dentry, old_name);
	return call_int_hook(path_link, old_dentry, new_dir, new_dentry);
	return call_int_hook(path_rename, old_dir, old_dentry, new_dir,
	return call_int_hook(path_truncate, path);
	return call_int_hook(path_chmod, path, mode);
	return call_int_hook(path_chown, path, uid, gid);
	return call_int_hook(path_chroot, path);
	return call_int_hook(inode_create, dir, dentry, mode);
/**
 * security_inode_post_create_tmpfile() - Update inode security of new tmpfile
 * @idmap: idmap of the mount
 * @inode: inode of the new tmpfile
 *
 * Update inode security data after a tmpfile has been created.
 */
void security_inode_post_create_tmpfile(struct mnt_idmap *idmap,
					struct inode *inode)
{
	if (unlikely(IS_PRIVATE(inode)))
		return;
	call_void_hook(inode_post_create_tmpfile, idmap, inode);
}

	return call_int_hook(inode_link, old_dentry, dir, new_dentry);
	return call_int_hook(inode_unlink, dir, dentry);
	return call_int_hook(inode_symlink, dir, dentry, old_name);
	return call_int_hook(inode_mkdir, dir, dentry, mode);
	return call_int_hook(inode_rmdir, dir, dentry);
	return call_int_hook(inode_mknod, dir, dentry, mode, dev);
		int err = call_int_hook(inode_rename, new_dir, new_dentry,
	return call_int_hook(inode_rename, old_dir, old_dentry,
	return call_int_hook(inode_readlink, dentry);
	return call_int_hook(inode_follow_link, dentry, inode, rcu);
	return call_int_hook(inode_permission, inode, mask);
	return call_int_hook(inode_setattr, idmap, dentry, attr);
/**
 * security_inode_post_setattr() - Update the inode after a setattr operation
 * @idmap: idmap of the mount
 * @dentry: file
 * @ia_valid: file attributes set
 *
 * Update inode security field after successful setting file attributes.
 */
void security_inode_post_setattr(struct mnt_idmap *idmap, struct dentry *dentry,
				 int ia_valid)
{
	if (unlikely(IS_PRIVATE(d_backing_inode(dentry))))
		return;
	call_void_hook(inode_post_setattr, idmap, dentry, ia_valid);
}

	return call_int_hook(inode_getattr, path);
	ret = call_int_hook(inode_setxattr, idmap, dentry, name, value, size,
			    flags);
	return ret;
	return call_int_hook(inode_set_acl, idmap, dentry, acl_name, kacl);
}

/**
 * security_inode_post_set_acl() - Update inode security from posix acls set
 * @dentry: file
 * @acl_name: acl name
 * @kacl: acl struct
 *
 * Update inode security data after successfully setting posix acls on @dentry.
 * The posix acls in @kacl are identified by @acl_name.
 */
void security_inode_post_set_acl(struct dentry *dentry, const char *acl_name,
				 struct posix_acl *kacl)
{
	if (unlikely(IS_PRIVATE(d_backing_inode(dentry))))
		return;
	call_void_hook(inode_post_set_acl, dentry, acl_name, kacl);
	return call_int_hook(inode_get_acl, idmap, dentry, acl_name);
	return call_int_hook(inode_remove_acl, idmap, dentry, acl_name);
}

/**
 * security_inode_post_remove_acl() - Update inode security after rm posix acls
 * @idmap: idmap of the mount
 * @dentry: file
 * @acl_name: acl name
 *
 * Update inode security data after successfully removing posix acls on
 * @dentry in @idmap. The posix acls are identified by @acl_name.
 */
void security_inode_post_remove_acl(struct mnt_idmap *idmap,
				    struct dentry *dentry, const char *acl_name)
{
	if (unlikely(IS_PRIVATE(d_backing_inode(dentry))))
		return;
	call_void_hook(inode_post_remove_acl, idmap, dentry, acl_name);
	return call_int_hook(inode_getxattr, dentry, name);
	return call_int_hook(inode_listxattr, dentry);
	ret = call_int_hook(inode_removexattr, idmap, dentry, name);
	return ret;
}

/**
 * security_inode_post_removexattr() - Update the inode after a removexattr op
 * @dentry: file
 * @name: xattr name
 *
 * Update the inode after a successful removexattr operation.
 */
void security_inode_post_removexattr(struct dentry *dentry, const char *name)
{
	if (unlikely(IS_PRIVATE(d_backing_inode(dentry))))
		return;
	call_void_hook(inode_post_removexattr, dentry, name);
	return call_int_hook(inode_need_killpriv, dentry);
	return call_int_hook(inode_killpriv, idmap, dentry);

	return call_int_hook(inode_getsecurity, idmap, inode, name, buffer,
			     alloc);

	return call_int_hook(inode_setsecurity, inode, name, value, size,
			     flags);
	return call_int_hook(inode_listsecurity, inode, buffer, buffer_size);
	return call_int_hook(inode_copy_up, src, new);
	rc = call_int_hook(inode_copy_up_xattr, name);
	if (rc != LSM_RET_DEFAULT(inode_copy_up_xattr))
		return rc;
	return LSM_RET_DEFAULT(inode_copy_up_xattr);
	return call_int_hook(kernfs_init_security, kn_dir, kn);
	return call_int_hook(file_permission, file, mask);
	rc = call_int_hook(file_alloc_security, file);
/**
 * security_file_release() - Perform actions before releasing the file ref
 * @file: the file
 *
 * Perform actions before releasing the last reference to a file.
 */
void security_file_release(struct file *file)
{
	call_void_hook(file_release, file);
}

	return call_int_hook(file_ioctl, file, cmd, arg);
	return call_int_hook(file_ioctl_compat, file, cmd, arg);
	return call_int_hook(mmap_file, file, prot, mmap_prot(file, prot),
			     flags);
	return call_int_hook(mmap_addr, addr);
	return call_int_hook(file_mprotect, vma, reqprot, prot);
	return call_int_hook(file_lock, file, cmd);
	return call_int_hook(file_fcntl, file, cmd, arg);
	return call_int_hook(file_send_sigiotask, tsk, fown, sig);
 * security_file_receive() - Check if receiving a file via IPC is allowed
	return call_int_hook(file_receive, file);
	ret = call_int_hook(file_open, file);
/**
 * security_file_post_open() - Evaluate a file after it has been opened
 * @file: the file
 * @mask: access mask
 *
 * Evaluate an opened file and the access mask requested with open(). The hook
 * is useful for LSMs that require the file content to be available in order to
 * make decisions.
 *
 * Return: Returns 0 if permission is granted.
 */
int security_file_post_open(struct file *file, int mask)
{
	return call_int_hook(file_post_open, file, mask);
}
EXPORT_SYMBOL_GPL(security_file_post_open);

	return call_int_hook(file_truncate, file);
	rc = call_int_hook(task_alloc, task, clone_flags);
	rc = call_int_hook(cred_alloc_blank, cred, gfp);
	rc = call_int_hook(cred_prepare, new, old, gfp);
	return call_int_hook(kernel_act_as, new, secid);
	return call_int_hook(kernel_create_files_as, new, inode);
 * security_kernel_module_request() - Check if loading a module is allowed
	return call_int_hook(kernel_module_request, kmod_name);
	return call_int_hook(kernel_read_file, file, id, contents);
	return call_int_hook(kernel_post_read_file, file, buf, size, id);
	return call_int_hook(kernel_load_data, id, contents);
	return call_int_hook(kernel_post_load_data, buf, size, id, description);
	return call_int_hook(task_fix_setuid, new, old, flags);
	return call_int_hook(task_fix_setgid, new, old, flags);
	return call_int_hook(task_fix_setgroups, new, old);
	return call_int_hook(task_setpgid, p, pgid);
	return call_int_hook(task_getpgid, p);
	return call_int_hook(task_getsid, p);
	return call_int_hook(task_setnice, p, nice);
	return call_int_hook(task_setioprio, p, ioprio);
	return call_int_hook(task_getioprio, p);
	return call_int_hook(task_prlimit, cred, tcred, flags);
	return call_int_hook(task_setrlimit, p, resource, new_rlim);
	return call_int_hook(task_setscheduler, p);
	return call_int_hook(task_getscheduler, p);
	return call_int_hook(task_movememory, p);
	return call_int_hook(task_kill, p, info, sig, cred);
	return call_int_hook(userns_create, cred);
	return call_int_hook(ipc_permission, ipcp, flag);
	rc = call_int_hook(msg_msg_alloc_security, msg);
	rc = call_int_hook(msg_queue_alloc_security, msq);
	return call_int_hook(msg_queue_associate, msq, msqflg);
	return call_int_hook(msg_queue_msgctl, msq, cmd);
	return call_int_hook(msg_queue_msgsnd, msq, msg, msqflg);
	return call_int_hook(msg_queue_msgrcv, msq, msg, target, type, mode);
	rc = call_int_hook(shm_alloc_security, shp);
	return call_int_hook(shm_associate, shp, shmflg);
	return call_int_hook(shm_shmctl, shp, cmd);
	return call_int_hook(shm_shmat, shp, shmaddr, shmflg);
	rc = call_int_hook(sem_alloc_security, sma);
	return call_int_hook(sem_associate, sma, semflg);
	return call_int_hook(sem_semctl, sma, cmd);
	return call_int_hook(sem_semop, sma, sops, nsops, alter);
			 u32 __user *size, u32 flags)
	u32 entrysize;
	u32 total = 0;
	u32 left;
			 u32 size, u32 flags)
	u64 required_len;
	if (size < lctx->len ||
	    check_add_overflow(sizeof(*lctx), lctx->ctx_len, &required_len) ||
	    lctx->len < required_len) {
	return call_int_hook(netlink_send, sk, skb);
 * security_ismaclabel() - Check if the named attribute is a MAC label
	return call_int_hook(ismaclabel, name);
	return call_int_hook(secid_to_secctx, secid, secdata, seclen);
	return call_int_hook(secctx_to_secid, secdata, seclen, secid);
	return call_int_hook(inode_notifysecctx, inode, ctx, ctxlen);
	return call_int_hook(inode_setsecctx, dentry, ctx, ctxlen);
	return call_int_hook(inode_getsecctx, inode, ctx, ctxlen);
	return call_int_hook(post_notification, w_cred, cred, n);
	return call_int_hook(watch_key, key);
	return call_int_hook(unix_stream_connect, sock, other, newsk);
	return call_int_hook(unix_may_send, sock, other);
	return call_int_hook(socket_create, family, type, protocol, kern);
	return call_int_hook(socket_post_create, sock, family, type,
	return call_int_hook(socket_socketpair, socka, sockb);
	return call_int_hook(socket_bind, sock, address, addrlen);
	return call_int_hook(socket_connect, sock, address, addrlen);
	return call_int_hook(socket_listen, sock, backlog);
	return call_int_hook(socket_accept, sock, newsock);
 * security_socket_sendmsg() - Check if sending a message is allowed
	return call_int_hook(socket_sendmsg, sock, msg, size);
	return call_int_hook(socket_recvmsg, sock, msg, size, flags);
	return call_int_hook(socket_getsockname, sock);
	return call_int_hook(socket_getpeername, sock);
	return call_int_hook(socket_getsockopt, sock, level, optname);
	return call_int_hook(socket_setsockopt, sock, level, optname);
	return call_int_hook(socket_shutdown, sock, how);
	return call_int_hook(socket_sock_rcv_skb, sk, skb);
	return call_int_hook(socket_getpeersec_stream, sock, optval, optlen,
			     len);
	return call_int_hook(socket_getpeersec_dgram, sock, skb, secid);
	return call_int_hook(sk_alloc_security, sk, family, priority);
	return call_int_hook(inet_conn_request, sk, skb, req);
	return call_int_hook(secmark_relabel_packet, secid);
	return call_int_hook(tun_dev_alloc_security, security);
	return call_int_hook(tun_dev_create);
	return call_int_hook(tun_dev_attach_queue, security);
	return call_int_hook(tun_dev_attach, sk, security);
	return call_int_hook(tun_dev_open, security);
	return call_int_hook(sctp_assoc_request, asoc, skb);
	return call_int_hook(sctp_bind_connect, sk, optname, address, addrlen);
	return call_int_hook(sctp_assoc_established, asoc, skb);
	return call_int_hook(mptcp_add_subflow, sk, ssk);
	return call_int_hook(ib_pkey_access, sec, subnet_prefix, pkey);
	return call_int_hook(ib_endport_manage_subnet, sec, dev_name, port_num);
	return call_int_hook(ib_alloc_security, sec);
	return call_int_hook(xfrm_policy_alloc_security, ctxp, sec_ctx, gfp);
	return call_int_hook(xfrm_policy_clone_security, old_ctx, new_ctxp);
	return call_int_hook(xfrm_policy_delete_security, ctx);
	return call_int_hook(xfrm_state_alloc, x, sec_ctx);
	return call_int_hook(xfrm_state_alloc_acquire, x, polsec, secid);
	return call_int_hook(xfrm_state_delete_security, x);
	return call_int_hook(xfrm_policy_lookup, ctx, fl_secid);
	return call_int_hook(xfrm_decode_session, skb, secid, 1);
	int rc = call_int_hook(xfrm_decode_session, skb, &flic->flowic_secid,
	return call_int_hook(key_alloc, key, cred, flags);
	return call_int_hook(key_permission, key_ref, cred, need_perm);
	return call_int_hook(key_getsecurity, key, buffer);
}

/**
 * security_key_post_create_or_update() - Notification of key create or update
 * @keyring: keyring to which the key is linked to
 * @key: created or updated key
 * @payload: data used to instantiate or update the key
 * @payload_len: length of payload
 * @flags: key flags
 * @create: flag indicating whether the key was created or updated
 *
 * Notify the caller of a key creation or update.
 */
void security_key_post_create_or_update(struct key *keyring, struct key *key,
					const void *payload, size_t payload_len,
					unsigned long flags, bool create)
{
	call_void_hook(key_post_create_or_update, keyring, key, payload,
		       payload_len, flags, create);
	return call_int_hook(audit_rule_init, field, op, rulestr, lsmrule);
	return call_int_hook(audit_rule_known, krule);
	return call_int_hook(audit_rule_match, secid, field, op, lsmrule);
	return call_int_hook(bpf, cmd, attr, size);
	return call_int_hook(bpf_map, map, fmode);
	return call_int_hook(bpf_prog, prog);
 * security_bpf_map_create() - Check if BPF map creation is allowed
 * @map: BPF map object
 * @attr: BPF syscall attributes used to create BPF map
 * @token: BPF token used to grant user access
 * Do a check when the kernel creates a new BPF map. This is also the
 * point where LSM blob is allocated for LSMs that need them.
int security_bpf_map_create(struct bpf_map *map, union bpf_attr *attr,
			    struct bpf_token *token)
	return call_int_hook(bpf_map_create, map, attr, token);
 * security_bpf_prog_load() - Check if loading of BPF program is allowed
 * @prog: BPF program object
 * @attr: BPF syscall attributes used to create BPF program
 * @token: BPF token used to grant user access to BPF subsystem
 * Perform an access control check when the kernel loads a BPF program and
 * allocates associated BPF program object. This hook is also responsible for
 * allocating any required LSM state for the BPF program.
int security_bpf_prog_load(struct bpf_prog *prog, union bpf_attr *attr,
			   struct bpf_token *token)
	return call_int_hook(bpf_prog_load, prog, attr, token);
}

/**
 * security_bpf_token_create() - Check if creating of BPF token is allowed
 * @token: BPF token object
 * @attr: BPF syscall attributes used to create BPF token
 * @path: path pointing to BPF FS mount point from which BPF token is created
 *
 * Do a check when the kernel instantiates a new BPF token object from BPF FS
 * instance. This is also the point where LSM blob can be allocated for LSMs.
 *
 * Return: Returns 0 on success, error on failure.
 */
int security_bpf_token_create(struct bpf_token *token, union bpf_attr *attr,
			      struct path *path)
{
	return call_int_hook(bpf_token_create, token, attr, path);
}

/**
 * security_bpf_token_cmd() - Check if BPF token is allowed to delegate
 * requested BPF syscall command
 * @token: BPF token object
 * @cmd: BPF syscall command requested to be delegated by BPF token
 *
 * Do a check when the kernel decides whether provided BPF token should allow
 * delegation of requested BPF syscall command.
 *
 * Return: Returns 0 on success, error on failure.
 */
int security_bpf_token_cmd(const struct bpf_token *token, enum bpf_cmd cmd)
{
	return call_int_hook(bpf_token_cmd, token, cmd);
}

/**
 * security_bpf_token_capable() - Check if BPF token is allowed to delegate
 * requested BPF-related capability
 * @token: BPF token object
 * @cap: capabilities requested to be delegated by BPF token
 *
 * Do a check when the kernel decides whether provided BPF token should allow
 * delegation of requested BPF-related capabilities.
 *
 * Return: Returns 0 on success, error on failure.
 */
int security_bpf_token_capable(const struct bpf_token *token, int cap)
{
	return call_int_hook(bpf_token_capable, token, cap);
	call_void_hook(bpf_map_free, map);
}

/**
 * security_bpf_prog_free() - Free a BPF program's LSM blob
 * @prog: BPF program struct
 *
 * Clean up the security information stored inside BPF program.
 */
void security_bpf_prog_free(struct bpf_prog *prog)
{
	call_void_hook(bpf_prog_free, prog);
 * security_bpf_token_free() - Free a BPF token's LSM blob
 * @token: BPF token struct
 * Clean up the security information stored inside BPF token.
void security_bpf_token_free(struct bpf_token *token)
	call_void_hook(bpf_token_free, token);
	return call_int_hook(locked_down, what);
	return call_int_hook(perf_event_open, attr, type);
	return call_int_hook(perf_event_alloc, event);
	return call_int_hook(perf_event_read, event);
	return call_int_hook(perf_event_write, event);
	return call_int_hook(uring_override_creds, new);
	return call_int_hook(uring_sqpoll);
	return call_int_hook(uring_cmd, ioucmd);